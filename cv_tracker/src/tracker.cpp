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
 @endverbatim
 *
 ******************************************************************************/

/******************************************************************************
 *
 * INCLUDE
 *
 ******************************************************************************/


#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include "opencv/cv.h"
#include <math.h>

//My Libs
#include "../inc/LED.h"
#include "../inc/Coord.h"
#include "../inc/Triangle.h"
#include "../inc/Camera.h"



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


int _arg_cam = 0;
//Global flags for command arguments
bool _arg_calibrate = false;
bool _arg_distance  = false;
bool _arg_points    = false;
bool _arg_booleans  = false;
bool _arg_ros       = false;

string _arg_conf     = "hsv.conf";

string intToString(int number);

Coord drawObject(LED light, Mat &frame);
void drawObject(vector<LED> lights, Mat &frame);
void trackFilteredObject(Mat thresh,Mat HSV, Mat &cameraFeed);
Coord trackFilteredObject(LED lights,Mat thresh,Mat HSV, Mat &cameraFeed);
void morpher(Mat &thresh);
ostream& operator<<(ostream& os, Coord& cd);
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
	
	
	//Matrix to store each frame of the webcam feed
	Mat cameraFeed, dest, camGray;
	Mat thresh, thresh2;
	Mat HSV;


	//video capture object to acquire webcam feed
	VideoCapture capture;
	//open capture object at location one (default location for usb cam)

	    capture.open(_arg_cam);

    //Fixes the VM from shitting the bed
	capture.set(CV_CAP_PROP_FRAME_WIDTH , 352);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT , 288);

	//set height and width of capture frame
	capture.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
	


	//infinite loop where all operations occur.
	while(1)
	{
		//store image to matrix
		capture.read(cameraFeed);
		
		//convert frame from BGR to HSV colorspace
		cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);

        /// Convert the image to Gray
        cvtColor( cameraFeed, camGray, CV_BGR2GRAY );
        threshold( camGray, dest, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU );
        imshow("CORCLES", dest);
	    //Create LEDs
	    LED green("green"), blue("blue"), red("red"), yellow("yellow");
	    
	    //Create Triangle
	    Triangle camTri;
	    
	    //Create the coordinate sets for all four blobs
        Coord p1, p2, p3, p4;
        
        //Set up Camera class that calculates distance based on focal length & 
        //observed object distance.
        Camera distCam;
        

          //threshold( cameraFeed, dest, 100, 255, 0 );

	    //Set up Red Tracker, send coordinates to p1
	    cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	    inRange(HSV,red.getHSVmin(),red.getHSVmax(),thresh);
        morpher(thresh);
	    p1 = trackFilteredObject(red,thresh,HSV,cameraFeed);
        imshow("RED", thresh);

        //inRange(HSV, Scalar(0, 70, 50), Scalar(10, 255, 255), thresh);
	    //inRange(HSV, Scalar(170, 70, 50), Scalar(180, 255, 255),thresh2);
        //Mat threshCombined = thresh | thresh2;
	    //morpher(threshCombined);
	    //p1 = trackFilteredObject(red,threshCombined,HSV,cameraFeed);
        //imshow("RED", threshCombined);

	    //Set up Green Tracker, send coordinates to p2
	    cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	    inRange(HSV,green.getHSVmin(),green.getHSVmax(),thresh);
	    morpher(thresh);
	    p2 = trackFilteredObject(green,thresh,HSV,cameraFeed);
        imshow("GREEN", thresh);

	    //Set up Blue Tracker, send coordinates to p3
	    cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	    inRange(HSV,blue.getHSVmin(),blue.getHSVmax(),thresh);
	    morpher(thresh);
	    p3 = trackFilteredObject(blue,thresh,HSV,cameraFeed);
        imshow("BLUE", thresh);

	    //Set up Yellow Tracker, send coordinates to p4
	    cvtColor(cameraFeed,HSV,COLOR_BGR2HSV);
	    inRange(HSV,yellow.getHSVmin(),yellow.getHSVmax(),thresh);
	    morpher(thresh);
	    p4 = trackFilteredObject(yellow,thresh,HSV,cameraFeed);
        imshow("YELLOW", thresh);

        //Display Image Feed in window
		imshow(winName,cameraFeed);

        //Set up the three sides of the Triangle
        if(p2.isTracking() && p3.isTracking())
            camTri.setSide("A", p2,p3);
        if(p3.isTracking() && p1.isTracking())
            camTri.setSide("B", p3,p1);
        if(p1.isTracking() && p2.isTracking())
            camTri.setSide("C", p1,p2);

        //Set the A,B,C sides of the triangle in the Camera Class        
        distCam.setA( camTri.getSide("A") );
        distCam.setB( camTri.getSide("B") );
        distCam.setC( camTri.getSide("C") );
        
        distCam.resetBlobs();
        if(p1.isTracking())
            distCam.incBlobs();
        if(p2.isTracking())
            distCam.incBlobs();
        if(p3.isTracking())
            distCam.incBlobs();
        //Print out distance to stdout
        if(_arg_calibrate)
        {

            //cout << "A: " << dist(p2,p3) << " | ";
            ///cout << "B: " << dist(p3,p1) << " | ";
            //cout << "C: " << dist(p1,p2) << endl;
        }
        if(_arg_distance)
        {
            cout << "DISTANCE: " << distCam.getDist() << endl;
        }
        if(_arg_points)
        {
            //cout <<   "A: " << camTri.getSide("A") << " | B: " << camTri.getSide("B") << " | C: " << camTri.getSide("C") << endl;
            cout <<   "Red: " << p1 << " Green: " << p2 << " Blue: " << p3 << " Yellow: " << p4 << endl;
        }
        if(_arg_booleans)
        {
            cout << distCam.blobTotal() << " blobs detected | ";
            cout << "Red  : " << p1.printTracking() << " | ";
            cout << "Green: " << p2.printTracking() << " | ";
            cout << "Blue : " << p3.printTracking() << endl;
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
 * @param[in] thresh - threshed image matrix
 * @param[in] HSV - Matrix containing HSV values
 * @param[in] cameraFeed - Matrix containing camera feed
 * 
 * @returns Set of coordinates in the Coord class structure, giving you (x,y)
 *
 *****************************************************************************/
Coord trackFilteredObject(LED lights,Mat thresh,Mat HSV, Mat &cameraFeed)
{
    //Maybe change all this so that It doesn't refer to everything as lights...
	LED blob;
	
	Coord coordinates;
	
	Mat tempMatrix;
	thresh.copyTo(tempMatrix);
	
	//findContours params
	vector<vector<Point> > contours;
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
 * @param[in] thresh - threshed image matrix
 *
 *****************************************************************************/
void morpher(Mat &thresh)
{
    //Erode and dilate the dense array to make the object clearly visible
    
    //Construct the erode
	Mat erodeElement  = getStructuringElement( MORPH_RECT, Size(3,3));
	Mat dilateElement = getStructuringElement( MORPH_RECT, Size(8,8));

	erode(thresh, thresh, erodeElement);
	erode(thresh, thresh, erodeElement);


	dilate(thresh, thresh, dilateElement);
	dilate(thresh, thresh, dilateElement);
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
        os << "( " << "N/A" << "," << "N/A" << " )";
    else
        os << "( " << cd.getX() << "," << cd.getY() << " )";
    return os;
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
    while ((c = getopt(argc, argv, "01234cdpbrh")) != -1)
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
                printf("CVTracker: running calibration mode (-c)\n");
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
                printf("    -c  run calibration mode.\n");
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

