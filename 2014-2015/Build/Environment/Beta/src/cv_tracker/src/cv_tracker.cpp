/*************************************************************************//**
 * @file tracker.cpp 
 *
 * @brief SOURCE - Blob detection software for determining distance
 *
 *
 * @section course_section CSC 465
 *
 * @author Julian Brackins
 *
 * @date December March, 10
 *
 * @par Professor:
 *         Dr. Jeff McGough
 *
 * @par Course:
 *         CSC 465 - M001 - Tues / Thurs - 9:00am
 *
 * @par Location:
 *         McLaury - 304
 *
 * @section program_section Program Information
 *
 * @details
 * This software should hopefully soon be adapted into a ROS publisher that is
 * capable of sending messages to our UAV to indicate the craft's distance from 
 * our landing pad situated on our Unmanned Ground Vechicle (UGV). This is done 
 * using three equidistant coloured dots, or "blobs" situated on our landing pad.
 * Utilizing OpenCv's libraries for tracking specific colours, these three blobs 
 * are recognized by the software's camera feed, with corresponding coordinates 
 * in relation to the camera feed's image plane. The software compares these values 
 * to the stored points read in from the configuration file in order to compare the 
 * observed size of the objects being tracked to the known size of these objects that 
 * has been previously calibrated and written to a config file.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      (Linux) - catkin_make
 *
 * @par Usage:
 @verbatim
 ./tracker -[options] [configfile]
 @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 * @todo General Code Cleanup, this is a mess lmaoooo
 * @todo Create configuration file for setting up what topics to listen to.
 * @todo Create configuration file for setting HSV values.
 * @todo Create configuration file for setting camera focal length.
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date              Modification
 ----------------  --------------------------------------------------------------
 * October  21, 2014    Uploading qr reader with distance algorithm
 *
 * November  4, 2014    Adding led stuff
 *
 * February  2, 2015    Set up LED tracking code 
 *
 * February  8, 2015    Created Coordinates and Triangle classes, need to start 
 *                      working on distance algorithm.
 *
 * February 16, 2015    Triangle is set up and printing, but lawOfCosines 
 *                      calculation isn't working right.
 *
 * February 21, 2015    Cleaning out led directory's cmake files so that code 
 *                      builds more easily on other machines
 *
 * February 22, 2015    Distance approximations now working through blob 
 *                      detection, Now just have to comment it all.... -.-
 *
 * February 28, 2015    A few tweaks
 *
 * March 10, 2015       Retooled tracker system so that it takes in command arguments 
 *                      properly. run <tracker -h> to see the command line options. 
 *                      Tracker can now determine distance from just two blobs. Need 
 *                      to implement config files still
 *
 * March 25, 2015       Calibration mode works now so that HSV values can be adjusted.
 *                      LED.cpp reflects accurate tracking of our really big landing 
 *                      pad image now. /CVRed, /CVBlue, /CVGreen have been converted 
 *                      into /CVPoints which tracks all three of the coordinates
 *                      and packages it into one topic.
 *
 * March 29, 2015       New ros topic, /CVCam, pushes out the video feed.
 *
 * April 20, 2015       Revised topic. Instead of initiating a camera, the cv_tracker
 *                      subscribes to the raw image feed set up by ar_track_alvar. 
 *                      This allows cv_tracker and ar_track_alvar to run concurrently
 *                      off of a unified camera feed.
 *
 @endverbatim
 *
 ******************************************************************************/

/******************************************************************************
 *
 * INCLUDE
 *
 ******************************************************************************/


//Libraries
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>
#include <math.h>

//My Libs
#include "../inc/LED.h"
#include "../inc/Coord.h"
#include "../inc/Triangle.h"
#include "../inc/Camera.h"

//ROS Stuff
#include "std_msgs/String.h"
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

//Open CV Stuff
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

//max number of objects to be detected in frame
const int MAX_OBJS = 50;

//minimum and maximum object area
const int MIN_OBJ_AREA = 15*15;
const int MAX_OBJ_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string winName = "Blob Detection";
const string threshName = "Threshold Image";
const string trackName = "HSV Callibration";
static const std::string OPENCV_WINDOW = "Image window";

//these will be the callibration HSV Values if running in
//Callibrations mode :)
int C_H_MIN = 0;
int C_H_MAX = 256;
int C_S_MIN = 0;
int C_S_MAX = 256;
int C_V_MIN = 0;
int C_V_MAX = 256;

int _arg_cam = 0;
//Global flags for command arguments
bool _arg_calibrate = false;
bool _arg_kalibrate = false;
bool _arg_distance  = false;
bool _arg_points    = false;
bool _arg_booleans  = false;
bool _arg_ros       = false;

string _arg_conf     = "hsv.conf";

/******************************************************************************
 *
 * Prototypes
 *
 ******************************************************************************/

string intToString(int number);
Coord drawObject(LED light, Mat &frame);
void drawObject(vector<LED> lights, Mat &frame);
void trackFilteredObject(Mat threshold,Mat HSV, Mat &cameraFeed);
Coord trackFilteredObject(LED lights,Mat threshold,Mat HSV, Mat &cameraFeed);
void morpher(Mat &threshold);
ostream& operator<<(ostream& os, Coord& cd);
double pixelDist(Coord c1, Coord c2);
void callibrationTrackers();
void on_trackbar( int, void* );
void Process_Arguments(int argc, char **argv);

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher img_pub;
  
  ros::Publisher cv_dist_pub;
  ros::Publisher cv_bools_pub;
  ros::Publisher cv_points_pub;
  
public:
  ImageConverter() : it_(nh_)
  {
    // Subscrive to input video feed and publish output video feed
    //This one for Hafiza's control panel
    image_sub_ = it_.subscribe("/usb_cam/image_raw", 1, &ImageConverter::imageCb, this);
    //This one when testing on my computer
    //image_sub_ = it_.subscribe("/image_raw", 1, &ImageConverter::imageCb, this);
    img_pub = it_.advertise("CVCam", 1);
    cv_dist_pub  = nh_.advertise<std_msgs::String>("CVDistance", 1000); // avg'd dist   | msg-> double
    cv_bools_pub = nh_.advertise<std_msgs::String>("CVBooleans", 1000); // GRB booleans | msg-> Green(a): bool | Red(b): bool | Blue(c): bool
    cv_points_pub = nh_.advertise<std_msgs::String>("CVPoints", 1000);   //Points rgb        | msg-> R( int , int ) | G( int , int ) | B( int , int )
    cv::namedWindow(OPENCV_WINDOW);
  }
  
  
  ~ImageConverter()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }

  void imageCb(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    Mat threshold;
    Mat HSV;

    //convert frame from BGR to HSV colorspace
    cvtColor(cv_ptr->image,HSV,COLOR_BGR2HSV);

    //Create LEDs
    LED green("green"), blue("blue"), red("red"), callibrate("calibrate");

    //Create Triangle
    Triangle camTri;

    //Create the coordinate sets for all three blobs
    Coord pA, pB, pC;

    //Set up Camera class that calculates distance based on focal length & 
    //observed object distance.
    Camera distCam;




    if(_arg_calibrate)
    {

      //if in calibration mode, we track objects based on the HSV slider values.
      cvtColor(cv_ptr->image,HSV,COLOR_BGR2HSV);
      inRange(HSV,Scalar(C_H_MIN,C_S_MIN,C_V_MIN),Scalar(C_H_MAX,C_S_MAX,C_V_MAX),threshold);
      morpher(threshold);
      imshow(threshName,threshold);
      callibrationTrackers();
      //trackFilteredObject(callibrate,threshold,HSV,cv_ptr->image);

      //imshow(winName,cv_ptr->image);
    }    
    else
    {
      //Set up Green Tracker, send coordinates to pA
      cvtColor(cv_ptr->image,HSV,COLOR_BGR2HSV);
      inRange(HSV,green.getHSVmin(),green.getHSVmax(),threshold);
      morpher(threshold);
      pA = trackFilteredObject(green,threshold,HSV,cv_ptr->image);

      //Set up Red Tracker, send coordinates to pB
      cvtColor(cv_ptr->image,HSV,COLOR_BGR2HSV);
      inRange(HSV,red.getHSVmin(),red.getHSVmax(),threshold);
      morpher(threshold);
      pB = trackFilteredObject(red,threshold,HSV,cv_ptr->image);
      //Display Image Feed in window                
      //Set up Blue Tracker, send coordinates to pC
      cvtColor(cv_ptr->image,HSV,COLOR_BGR2HSV);
      inRange(HSV,blue.getHSVmin(),blue.getHSVmax(),threshold);
      morpher(threshold);
      pC = trackFilteredObject(blue,threshold,HSV,cv_ptr->image);

      //No longer showing this because the Odroid wouldn't have a display port anyways...
      //The image feed is being published so just do <rosrun cv_tracker vidfeed>
      //imshow(winName,cv_ptr->image);

      //Set up the three sides of the Triangle
      if(pB.isTracking() && pC.isTracking())
        camTri.setSide("A", pB,pC);
      if(pC.isTracking() && pA.isTracking())
        camTri.setSide("B", pC,pA);
      if(pA.isTracking() && pB.isTracking())
        camTri.setSide("C", pA,pB);

      //Set the A,B,C sides of the triangle in the Camera Class        
      distCam.setA( camTri.getSide("A") );
      distCam.setB( camTri.getSide("B") );
      distCam.setC( camTri.getSide("C") );

      distCam.resetBlobs();
      if(pA.isTracking())
        distCam.incBlobs();
      if(pB.isTracking())
        distCam.incBlobs();
      if(pC.isTracking())
        distCam.incBlobs();
          

      cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
      //Print out distance to stdout

      if(_arg_kalibrate)
      {
        //(k)alibration mode 2 overrides everything else. Just want pixel distances..
        double pix_a, pix_b, pix_c;
        
        pix_a = pixelDist( pB , pC );
        pix_b = pixelDist( pA , pC );
        pix_c = pixelDist( pA , pB );
        
        cout << "PIXEL    : Side a: " << pix_a;
        cout <<         " | Side b: "   << pix_b;
        cout <<         " | Side c: "  << pix_c << endl;
        
      }
      else
      {
        //Run normally
        if(_arg_distance)
        {
          cout << "DISTANCE : " << setfill('0') << setprecision(10) << distCam.getDist() << endl;
        }
        if(_arg_points)
        {
          cout << "POINTS   : Green(a): " << pA;
          cout <<         " | Red(b): "   << pB;
          cout <<         " | Blue(c): "  << pC << endl;
          //  printf("POINTS  : Green(a): %f | ", camTri.getSide("A"));
          //  printf(          "Red(b): %f | ", camTri.getSide("B"));
          //  printf(          "Blue(c): %f \n", camTri.getSide("C"));
        }
        if(_arg_booleans)
        {
          cout << "BOOLEANS : Green(a): " << "(   " << pA.printTracking() << "   )";
          cout <<         " | Red(b): "   << "(   " << pB.printTracking() << "   )"; 
          cout <<         " | Blue(c): "  << "(   " << pC.printTracking() << "   )" << endl;
        }
        if(_arg_ros)
        {
          std_msgs::String msg;
          std::stringstream ss;

          //Distance
          ss << setfill('0') << setprecision(10) << setfill('0') << distCam.getDist()  ;
          msg.data = ss.str();
          cv_dist_pub.publish(msg); 

          //Booleans            
          ss.str(std::string());
          ss <<    "Green(a): " << setprecision(5) << pA.isTracking();
          ss << " | Red(b): "   << pB.isTracking();
          ss << " | Blue(c): "  << pC.isTracking();
          msg.data = ss.str();
          cv_bools_pub.publish(msg); 

          //Points
          ss.str(std::string());
          ss << "Green(a): " << pA << " | ";
          ss << "Red(b): " << pB << " | ";
          ss << "Blue(c):" << pC;

          //Send out the video using image pointers.
          msg.data = ss.str();
          cv_points_pub.publish(msg);
          sensor_msgs::ImagePtr vidmsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", cv_ptr->image).toImageMsg();
          img_pub.publish(vidmsg);
        }
      }       
    }
    // Draw an example circle on the video stream
    //if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
    //  cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));
    // Update GUI Window
    cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);

    // Output modified video stream
    img_pub.publish(cv_ptr->toImageMsg());
    //End imageCb
  }
  //End class ImageConverter
};



int main(int argc, char** argv)
{
  Process_Arguments( argc, argv);
  ros::init(argc, argv, "image_converter");
  ImageConverter ic;
  ros::spin();
  return 0;
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Convert integers to strings lmaoooo.
 *
 * @param[in] number - an integer lmfaoo.
 * 
 * @returns that number as a STRING yo
 *
 *****************************************************************************/
string intToString(int number)
{
	std::stringstream ss;
	ss << number;
	return ss.str();
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Convert integers to strings lmaoooo.
 *
 * @param[in] light - an led light being tracked
 * @param[in] frame - image matrix
 * 
 * @returns Set of coordinates in the Coord class structure, giving you (x,y)
 *
 *****************************************************************************/
Coord drawObject(LED light, Mat &frame)
{
  //Draw a circle around the object being tracked

  cv::circle( frame, cv::Point( light.getX(),light.getY() ), 10, cv::Scalar(0,0,255));
  cv::putText(frame, intToString( light.getX() ) + " , " + intToString( light.getY() ), 
  cv::Point(light.getX(), light.getY() + 20 ), 1, 1, cv::Scalar(0,255,0));
  Coord point;
  point.setX(light.getX());
  point.setY(light.getY());
  return point;
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * After the images have been filtered properly, this function
 * handles determining if an image contains a blob that fits in the HSV range
 * of the colour being tracked.
 *
 * @param[in] light - an led light being tracked
 * @param[in] threshold - thresholded image matrix
 * @param[in] HSV - Matrix containing HSV values
 * @param[in] cameraFeed - Matrix containing camera feed
 * 
 * @returns Set of coordinates in the Coord class structure, giving you (x,y)
 *
 *****************************************************************************/
Coord trackFilteredObject(LED lights,Mat threshold,Mat HSV, Mat &cameraFeed)
{
  //Maybe change all this so that It doesn't refer to everything as lights...
  LED blob;

  Coord coordinates;

  Mat tempMatrix;
  threshold.copyTo(tempMatrix);

  //findContours params
  vector<vector<Point>> contours;
  vector<Vec4i> hierarchy;

  //find the contours of the image using openCV
  findContours( tempMatrix, contours, hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );

  //use moments method to find our filtered object
  double refArea = 0;
  bool objectFound = false;

  //Zero out the coordinates
  coordinates.setX(0);
  coordinates.setY(0);

  if (hierarchy.size() > 0) 
  {
    int numObjects = hierarchy.size();
    //The filter becomes too noisy if the numObjects is too great...
    if(numObjects < MAX_OBJS)
    {
      for (int i = 0; i >= 0; i = hierarchy[i][0]) 
      {
        Moments moment = moments((cv::Mat)contours[i]);
        double area = moment.m00;

        //if the area is less than 20 px by 20px then it is probably just noise
        //if the area is the same as the 3/2 of the image size, probably just a bad filter
        //we only want the object with the largest area so we safe a reference area each
        //iteration and compare it to the area in the next iteration.
        if(area>MIN_OBJ_AREA)
        {
          blob.setX(moment.m10/area);
          blob.setY(moment.m01/area);
          blob.setColour(lights.getColour());
          blob.setText(lights.getText());

          //Push onto vector if allowing multiples of one colour
          //blobvec.push_back(blob);
          objectFound = true;
        }
        else 
          objectFound = false;
      }
      
      //let user know you found an object
      if(objectFound ==true)
      {
        //draw object location on screen
        //use vector version of drawObject if allowing multiples
        coordinates = drawObject(blob,cameraFeed);
        coordinates.setTracking(true);
      }
      else
      {
        coordinates.setTracking(false);
      }
    }
    else putText(cameraFeed,"Adjust Filter, too much noise.",Point(0,50),1,2,Scalar(0,0,255),2);
  }
  return coordinates;
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Morphing function to properly erod and dilate the dense array to enhance 
 * image visibility.
 *
 * @param[in] threshold - thresholded image matrix
 *
 *****************************************************************************/
void morpher(Mat &threshold)
{
  //Erode and dilate the dense array to make the object clearly visible
  //Construct the erode
  Mat erodeElement  = getStructuringElement( MORPH_RECT, Size(3,3));
  Mat dilateElement = getStructuringElement( MORPH_RECT, Size(8,8));

  erode(threshold, threshold, erodeElement);
  erode(threshold, threshold, erodeElement);


  dilate(threshold, threshold, dilateElement);
  dilate(threshold, threshold, dilateElement);
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Overloaded output stream for the Coord class. Might as well toss this
 * eventually because I'll most likely be switching to printf anyways... hehe.
 *
 * @param[in] os - outstream.
 * @param[in] cd - representatoin of Coord class indicating how output works
 *
 * @returns os - output stream
 *
 *****************************************************************************/
ostream& operator<<(ostream& os,  Coord& cd)
{
  //Overloaded Coord << operator
  if (cd.getX() == 0 || cd.getY() == 0)
    os << "( " << "N/A" << " , " << "N/A" << " )";
  else
  {
    os << "( "  << setw(3) << cd.getX();
    os << " , " << setw(3) << cd.getY() << " )";
  }
  return os;
}

double pixelDist(Coord c1, Coord c2)
{
  double xSq, ySq;
  xSq = c2.getX() - c1.getX(); 
  xSq = xSq * xSq;
  ySq = c2.getY() - c1.getY();
  ySq = ySq * ySq;

  return sqrt( xSq + ySq );
}

void callibrationTrackers()
{
  //create window for trackbars
  namedWindow(trackName,0);
  //create memory to store trackbar name on window
  char TrackbarName[50];
  sprintf( TrackbarName, "H_MIN", C_H_MIN);
  sprintf( TrackbarName, "H_MAX", C_H_MAX);
  sprintf( TrackbarName, "S_MIN", C_S_MIN);
  sprintf( TrackbarName, "S_MAX", C_S_MAX);
  sprintf( TrackbarName, "V_MIN", C_V_MIN);
  sprintf( TrackbarName, "V_MAX", C_V_MAX);

  //set up the HSV trackbars to allow callibration to occur. have fuuuuun :)
  createTrackbar( "H_MIN", trackName, &C_H_MIN, C_H_MAX, on_trackbar );
  createTrackbar( "H_MAX", trackName, &C_H_MAX, C_H_MAX, on_trackbar );
  createTrackbar( "S_MIN", trackName, &C_S_MIN, C_S_MAX, on_trackbar );
  createTrackbar( "S_MAX", trackName, &C_S_MAX, C_S_MAX, on_trackbar );
  createTrackbar( "V_MIN", trackName, &C_V_MIN, C_V_MAX, on_trackbar );
  createTrackbar( "V_MAX", trackName, &C_V_MAX, C_V_MAX, on_trackbar );
}

void on_trackbar( int, void* )
{
  //This function gets called whenever a
  // trackbar position is changed
}

/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Super sophisticated arguments processor that I made back at NASA woo. 
 * Handles a bunch of different option flags brought in through command line
 * arguments. The first command argument is the program name (./tracker), the
 * second argument is the list of option flags, and the third option is the
 * configuration file being read in. Each flag that is read in will modify a
 * global flag that will determine how the program is executed.
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/
void Process_Arguments(int argc, char **argv)
{
  int c;
  printf("CVTracker: argc=%d, argv=%s\n", argc-1, argv[1]);
  //tokenize each param and check it individually
  while ((c = getopt(argc, argv, "01234ckdpbrh")) != -1)
  {
    switch (c)
    {
      case '0':
        _arg_cam = 0;
        printf("CVTracker: using camera 0 (-0)\n");
        break;
      case '1':
        _arg_cam = 1;
        printf("CVTracker: using camera 1 (-1)\n");
        break;
      case '2':
        _arg_cam = 2;
        printf("CVTracker: using camera 2 (-2)\n");
        break;
      case '3':
        _arg_cam = 3;
        printf("CVTracker: using camera 3 (-3)\n");
        break;
      case '4':
        _arg_cam = 4;
        printf("CVTracker: using camera 4 (-4)\n");
        break;
      case 'c':
        _arg_calibrate = true;
        printf("CVTracker: running calibration mode 1(-c)\n");
        break;
      case 'k':
        _arg_kalibrate = true;
        printf("CVTracker: running calibration mode 2(-k)\n");
        break;
      case 'd':
        _arg_distance = true;
        printf("CVTracker: printing Object Distance to stdout (-d)\n");
        break;
      case 'p':
        _arg_points = true;
        printf("CVTracker: printing RGB point coordinates to stdout (-p)\n");
        break;
      case 'b':
        _arg_booleans = true;
        printf("CVTracker: printing blob tracking booleans (-b)\n");
        break;
      case 'r':
        _arg_ros = true;
        printf("CVTracker: publishing to ROS (-r)\n");
        break;
      case 'h':
        printf("CVTracker: help\n");
        printf("$ %s [-options] [logfile] \n", argv[0]);
        printf("    Please place a - then however many of the following [option] values:\n");
        printf("    -#  select which camera to use ( 0 - 4, 0 is default).\n");
        printf("    -c  run (c)alibration mode 1: HSV Testing.\n");
        printf("    -k  run (k)alibration mode 2: Camera Testing.\n");
        printf("    -d  ouput object distance to stdout\n");
        printf("    -p  print RGB point coordinates to stdout\n");
        printf("    -b  print blob tracking booleans (true=tracking / false=not tracking)\n");
        printf("    -r  publish info to ROS\n");
        printf("    -h  display help\n");
        printf("    If no [logfile] specified then the default\n");
        printf("    \"hsv.conf\" will be used.\n");
        exit(0);
        break;
      default:
        //gStandalone = 0;
        printf("CVTracker: ignoring option -%c\n", c);
        break;
    }
  }
  /** 
  * Handle the configuration file here.
  **/
  if( argc > 2 )
  {
    _arg_conf = argv[2];
    printf("CVTracker: reading HSV & focal length settings from configuration file: \"%s\"\n", argv[2]);
  }
  else
  {
    printf("CVTracker: reading HSV & focal length settings from default file: \"hsv.conf\"\n");
  }
}
