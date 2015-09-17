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

//OpenCV
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"

//My Libs
#include "../inc/LED.h"
#include "../inc/Coord.h"
#include "../inc/Triangle.h"
#include "../inc/Camera.h"

//ROS
#include "ros/ros.h"
#include "std_msgs/String.h"

//cv_bridge
#include "image_transport/image_transport.h"
#include "sensor_msgs/image_encodings.h"
#include "cv_bridge/cv_bridge.h"

using namespace cv;
using namespace std;

//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

//max number of objects to be detected in frame
const int MAX_OBJS=50;

//minimum and maximum object area
const int MIN_OBJ_AREA = 15*15;
const int MAX_OBJ_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;
//names that will appear at the top of each window
const string winName = "Blob Detection";
const string threshName = "Threshold Image";
const string trackName = "HSV Callibration";

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


/******************************************************************************
 * @author Julian Brackins
 *
 * @par Description:
 * Set up infinite loop for program. Sorry for using main() for my whole prog..
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/
int main(int argc, char* argv[])
{
    //true to set calibration
    
    Process_Arguments( argc, argv);
	

	  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  
  image_transport::ImageTransport it(n);
  image_transport::Subscriber img_sub;
  image_transport::Publisher img_pub;
  
  

  img_pub = it.advertise("CVCam", 1);
  //Set up cv_bridge pointer
  cv_bridge::CvImagePtr cv_ptr;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
ros::Publisher cv_dist_pub  = n.advertise<std_msgs::String>("CVDistance", 1000); // avg'd dist   | msg-> double
ros::Publisher cv_bools_pub = n.advertise<std_msgs::String>("CVBooleans", 1000); // GRB booleans | msg-> Green(a): bool | Red(b): bool | Blue(c): bool

ros::Publisher cv_points_pub = n.advertise<std_msgs::String>("CVPoints", 1000);   //Points rgb        | msg-> R( int , int ) | G( int , int ) | B( int , int )

//Not pubbing these out separately anymore :(
/*
ros::Publisher cv_green_pub = n.advertise<std_msgs::String>("CVGreen", 1000);   //Point a        | msg-> ( int , int )
ros::Publisher cv_red_pub   = n.advertise<std_msgs::String>("CVRed"  , 1000);   //Point b        | msg-> ( int , int )
ros::Publisher cv_blue_pub  = n.advertise<std_msgs::String>("CVBlue" , 1000);   //Point c        | msg-> ( int , int )
*/
	//Matrix to store each frame of the webcam feed
	Mat cameraFeed;
	Mat threshold;
	Mat HSV;


	//video capture object to acquire webcam feed
	VideoCapture capture;
	//open capture object at location one (default location for usb cam)

	    capture.open(_arg_cam);

    if(_arg_calibrate)
    		callibrationTrackers();
	
	//set height and width of capture frame
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
	
	//infinite loop where all operations occur.
	int count = 0;
	while(ros::ok())
	{
		//store image to matrix
		capture.read(cameraFeed);
		
		//convert frame from BGR to HSV colorspace
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);

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
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
		inRange(HSV,Scalar(C_H_MIN,C_S_MIN,C_V_MIN),Scalar(C_H_MAX,C_S_MAX,C_V_MAX),threshold);
		morpher(threshold);
		imshow(threshName,threshold);
		//trackFilteredObject(callibrate,threshold,HSV,cameraFeed);
		
				imshow(winName,cameraFeed);
        }    
        else
        {
	        //Set up Green Tracker, send coordinates to pA
	        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	        inRange(HSV,green.getHSVmin(),green.getHSVmax(),threshold);
	        morpher(threshold);
	        pA = trackFilteredObject(green,threshold,HSV,cameraFeed);

	        //Set up Red Tracker, send coordinates to pB
	        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	        inRange(HSV,red.getHSVmin(),red.getHSVmax(),threshold);
	        morpher(threshold);
	        pB = trackFilteredObject(red,threshold,HSV,cameraFeed);
            //Display Image Feed in window                
	        //Set up Blue Tracker, send coordinates to pC
	        cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	        inRange(HSV,blue.getHSVmin(),blue.getHSVmax(),threshold);
	        morpher(threshold);
	        pC = trackFilteredObject(blue,threshold,HSV,cameraFeed);
	        
	        //No longer showing this because the Odroid wouldn't have a display port anyways...
	        //The image feed is being published so just do <rosrun cv_tracker vidfeed>
		    imshow(winName,cameraFeed);

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
                    sensor_msgs::ImagePtr vidmsg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", cameraFeed).toImageMsg();
                    img_pub.publish(vidmsg);
                    
                }
            }       
        }
		//delay 30ms so that screen can refresh.
		//image will not appear without this waitKey() command
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            break; 
        }
	}
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
				else objectFound = false;
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
