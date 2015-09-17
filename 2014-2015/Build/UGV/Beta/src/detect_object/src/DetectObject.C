/*************************************************************************//**
 * @file DetectObject.C 
 *
 * @brief SOURCE - .
 *
 * @mainpage 
 *
 * @section course_section CSC 465
 *
 * @author Samuel Carroll & Alex Wulff
 *
 * @date April 2015
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
 * This will use the data from the ROS API to detect any objects that we can see
 * and publish their location so that the path planner can navigate around them.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      (Linux) - catkin_make
 *
 * @par Usage:
 @verbatim
 rosrun detectObj detectObj
 @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date              Modification
 ----------------  --------------------------------------------------------------
 * February 2015	Started setting up a device to send out point cloud data
 * February 2015	Using Asus Kinect we have a device that can stream data
 * March 2015		Getting point cloud data in human readable format started work
 * March 2015		Detecting Objects in two still frame snaps Working on streaming data
 * April 2015		Getting Data streaming having issues, started setting up subscriber
 *
 @endverbatim
 *
 ******************************************************************************/

 /******************************************************************************
 *
 * INCLUDE
 *
 ******************************************************************************/
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Float32MultiArray.h"

#include <iostream>
#include <fstream>
#include <list>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

/*****************************************************************************
 *
 * USING
 *
***************************************************************//*************/
using namespace std;

/*****************************************************************************
 *
 * STRUCTS
 *
***************************************************************//*************/
struct plane
{
  float i;
  float j;
  float k;
};

struct point
{
  float xDistance;
  float yDistance;
  float zDistance;
};

struct rowcol
{
  int row;
  int col;
};

/*****************************************************************************
 *
 * FUNCTION DEFINITIONS
 *
***************************************************************//*************/
void closeFile ( ifstream &fin );
void deleteImage ( vector < vector < point > > &image );
float findAngle (plane objectPlane);
void findObjects (vector < vector < point > > &image);
void getPlane (plane &newPlane, point p0, point p1, point p2, point p3, point p4, point p5, point p6);
float getValue ( string &line, bool isZ );
bool isObject ( vector < vector < point > > &image, int row, int col );
void readImage ( const std_msgs::Float32MultiArray::ConstPtr &msg, vector < vector < point > > &image );
void readRow ( string &msg, point &newPoint );
void readline ( string &msg, string &line );
bool sameObject ( point found, point currPoint);
bool scanArea (vector < vector < point > > &image, rowcol currRowCol, list<rowcol>::iterator currPos);
void scanRows (vector < vector < point > > &image, int row, int &goLeft, int &goRight);
bool isValidPoint (point checkPoint);

/******************************************************************************

                                     TODO

Change file input to ros stream input

                                     NOTE
The first column is the X distance
The second column is the Y distance
The third column is the Z distance

***************************************************************//*************/

/*****************************************************************************
 *
 * CONSTANTS
 *
***************************************************************//*************/
const int MINDIST = 4;
const float PI = 3.14159;
const int maxAngle = 30;

/******************************************************************************
 *
 * GLOBALS
 *
******************************************************************************/
ros::Publisher DetectObjStream_pub;
plane _drivePlane;
list<rowcol> _lastSweep;
list<rowcol> _currSweep;
vector<point> foundObjects;

/******************************************************************************
 * 
 * @author Samuel Carroll
 *
 * @par Description:
 * Callback for Detect Object. X Y and Z data of known objects
 *
 * @param[in] msg - the message being sent down the topic. 
 *
* ***************************************************************//*************/
void detectCallback(const std_msgs::Float32MultiArray::ConstPtr &msg)
{
  //string msgStr = msg->data;
  
  vector < vector < point > > image;

  readImage ( msg, image);

  getPlane( _drivePlane, image[5][120], image[5][115], image[5][125], image[0][118], image[0][122], image[10][118], image[10][122]);

  findObjects( image );
  deleteImage (image);
}

/******************************************************************************
 * Samuel Carroll
 *
 * @par Description:
 * This is the main processing function for the program. Currently it is set up
 * to open a human readable depth file and then remove the header info for that
 * file (so we can used the distances for detecting objects). We then read in the
 * distance information and decide if there are trouble areas, if there are we
 * numbers have the same sign (both > 0 or both < 0) if both are - go right if
 * both are + go left. If we have different signs we will need to find which is
 * farther from 0. Output the distance we should go.
 *
***************************************************************//*************/
int main (int argc, char **argv)
{
  string temp;
  point newPoint;
  point depthImage;
  vector < vector < point > > image;
  srand(time(NULL));
  
   // Slam Conversions
  ros::init(argc, argv, "DetectObj");

  ros::NodeHandle detectObj;
  
  // publisher
  DetectObjStream_pub = detectObj.advertise<std_msgs::String>("DetectObjStream", 1);

  // subscribe
  ros::Subscriber sub = detectObj.subscribe("SlamStream", 1, detectCallback);
  
  // wait for stuff
  ros::spin();

  return 0;

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Closes a input file stream
 *
 * @param[in] fin - the input file stream to be closed. 
 *
 * TODO: Remove from the code won't be needed
***************************************************************//*************/
void closeFile ( ifstream &fin )
{

  fin.close( );

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Deletes a given image from memory to prevent any data leaks
 *
 * @param[in] image - the image vector to be deleted. 
***************************************************************//*************/
void deleteImage ( vector < vector < point > > &image )
{
  for (int i = 0; i < 240; i++)
  {
   image [i].clear(); // delete the row we are at
  }
  
  image.clear(); //delete all the remaining vectors
  
}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Using a object plane we find the angle from our drive angle and return this
 *
 * @param[in] objectPlane - the plane of the object we are checking against. 
 * @param[out] angle - the angle between the object and the drive plane
***************************************************************//*************/
float findAngle (plane objectPlane)
{
  float numerator;
  float denominator;
  float mag;
  float objectMag;
  float angle;

  numerator = ( _drivePlane.i * objectPlane.i ) + ( _drivePlane.j * objectPlane.j ) + ( _drivePlane.k * objectPlane.k );

  if ( numerator < 0 )
    numerator *= -1;

  if ( numerator == 0 )
    return 0;

  mag = (_drivePlane.i * _drivePlane.i) + (_drivePlane.j * _drivePlane.j) + (_drivePlane.k * _drivePlane.k);
  objectMag = (objectPlane.i * objectPlane.i) + (objectPlane.j *objectPlane.j) + (objectPlane.k * objectPlane.k);

  mag = sqrt ( mag );
  objectMag = sqrt ( objectMag );

  denominator = mag * objectMag;

  angle = acos ( numerator / denominator );

  angle *= ( 180 / PI );

  if ( angle >= 180 )
    angle -= 180;
  else if ( angle > 90)
    angle = 180 - angle;

  return angle;

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function will traverse the image looking for points in a given threshold.
 * If a point is in the threshold we will look around the point and try to 
 * determine if the point is an object or just an anomaly by flagging trouble 
 * spots. If we decide it is an object we will find its plane and decide if it 
 * will be troublesome (>30 degrees to the drive plane).
 * 
 * @param[in] image - the image we are looking for objects in. 
***************************************************************//*************/
void findObjects (vector < vector < point > > &image)
{
  int goLeft = 0;
  int goRight = 0;

  // if the object is within the minimum threshold try to find the object plane
  // do this by taking points around it in the i and j positions and if they are
  // about the same distance away assume they are the same object

  // start at multiple rows and see if we have any trouble areas save all trouble
  // i and j zones that we found on the previous sweep and see if the object is 
  // still there, if so 

  int listSize = _lastSweep.size();
  list<rowcol>::iterator lastSweepIter;

  if (listSize > 0)
  {
    for (lastSweepIter = _lastSweep.begin(); lastSweepIter != _lastSweep.end(); lastSweepIter++)
    {
      if (!scanArea(image, *lastSweepIter, lastSweepIter))
      {
        // remove from our _lastSweep list
	list<rowcol>::iterator tempIter = lastSweepIter;
	
	if (!_lastSweep.size() != 1)
	{
          lastSweepIter--; // decrement by one so we don't skip a possible object.
	}
	
	_lastSweep.erase(tempIter);
      }
    }
  }
  
  // put in a for loop that scans 8 random rows that aren't equal to each other
  // then save the trouble spots (i and j) so we can determine what to do
  // If an object is still there avoid if not it moved and keep going
  for (int scannedRows = 0; scannedRows < 30; scannedRows++)
  {
    // scan random rows looking for troubled spots
    int scanRow = rand() % 240; // randomly choose a row from 0-239
    scanRows (image, scanRow, goLeft, goRight); // scan that row
  }

  _lastSweep.splice(_lastSweep.end(), _currSweep); // add all elements from _currSweep to _lastSweep
  _currSweep.clear(); // ensure _currSweep is empty
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * This function will take in seven points and find a plane that all of the
 * points lie on. This will be used to generate our driving plane.
 *
 * @param[in] newPlane - the plane we will find, sets it. 
 * @param[in] p0 - first point of the plane
 * @param[in] p1 - second point of the plane
 * @param[in] p2 - third point of the plane
 * @param[in] p3 - fourth point of the plane
 * @param[in] p4 - fifth point of the plane
 * @param[in] p5 - sixth point of the plane
 * @param[in] p6 - seventh point of the plane
***************************************************************//*************/
void getPlane (plane &newPlane, point p0, point p1, point p2, point p3, point p4, point p5, point p6)
{
  float iTemp = 0, jTemp = 0, kTemp =0;

  newPlane.i = 0;
  newPlane.j = 0;
  newPlane.k = 0;

  // p0, p1 ,p2
  iTemp += ((p0.yDistance-p1.yDistance)*(p0.zDistance-p2.zDistance))
         - ((p0.zDistance-p1.zDistance)*(p0.yDistance-p2.yDistance));
  jTemp += -1 * (((p0.xDistance-p1.xDistance)*(p0.zDistance-p2.zDistance))
              - ((p0.zDistance-p1.zDistance)*(p0.xDistance-p2.xDistance)));
  kTemp += ((p0.xDistance-p1.xDistance)*(p0.yDistance-p2.yDistance))
         - ((p0.yDistance-p1.yDistance)*(p0.xDistance-p2.xDistance));

  // p0, p2 ,p3
  iTemp += ((p0.yDistance-p2.yDistance)*(p0.zDistance-p3.zDistance))
         - ((p0.zDistance-p2.zDistance)*(p0.yDistance-p3.yDistance));
  jTemp += -1 * (((p0.xDistance-p2.xDistance)*(p0.zDistance-p3.zDistance))
              - ((p0.zDistance-p2.zDistance)*(p0.xDistance-p3.xDistance)));
  kTemp += ((p0.xDistance-p2.xDistance)*(p0.yDistance-p3.yDistance))
         - ((p0.yDistance-p2.yDistance)*(p0.xDistance-p3.xDistance));

  // p0, p3 ,p4
  iTemp += ((p0.yDistance-p3.yDistance)*(p0.zDistance-p4.zDistance))
         - ((p0.zDistance-p3.zDistance)*(p0.yDistance-p4.yDistance));
  jTemp += -1 * (((p0.xDistance-p3.xDistance)*(p0.zDistance-p4.zDistance))
              - ((p0.zDistance-p3.zDistance)*(p0.xDistance-p4.xDistance)));
  kTemp += ((p0.xDistance-p3.xDistance)*(p0.yDistance-p4.yDistance))
         - ((p0.yDistance-p3.yDistance)*(p0.xDistance-p4.xDistance));

  // p0, p4 ,p5
  iTemp += ((p0.yDistance-p4.yDistance)*(p0.zDistance-p5.zDistance))
         - ((p0.zDistance-p4.zDistance)*(p0.yDistance-p5.yDistance));
  jTemp += -1 * (((p0.xDistance-p4.xDistance)*(p0.zDistance-p5.zDistance))
              - ((p0.zDistance-p4.zDistance)*(p0.xDistance-p5.xDistance)));
  kTemp += ((p0.xDistance-p4.xDistance)*(p0.yDistance-p5.yDistance))
         - ((p0.yDistance-p4.yDistance)*(p0.xDistance-p5.xDistance));

  // p0, p5 ,p6
  iTemp += ((p0.yDistance-p5.yDistance)*(p0.zDistance-p6.zDistance))
         - ((p0.zDistance-p5.zDistance)*(p0.yDistance-p6.yDistance));
  jTemp += -1 * (((p0.xDistance-p5.xDistance)*(p0.zDistance-p6.zDistance))
              - ((p0.zDistance-p5.zDistance)*(p0.xDistance-p6.xDistance)));
  kTemp += ((p0.xDistance-p5.xDistance)*(p0.yDistance-p6.yDistance))
         - ((p0.yDistance-p5.yDistance)*(p0.xDistance-p6.xDistance));

  // p0, p6 ,p1
  iTemp += ((p0.yDistance-p6.yDistance)*(p0.zDistance-p1.zDistance))
         - ((p0.zDistance-p6.zDistance)*(p0.yDistance-p1.yDistance));
  jTemp += -1 * (((p0.xDistance-p6.xDistance)*(p0.zDistance-p1.zDistance))
              - ((p0.zDistance-p6.zDistance)*(p0.xDistance-p1.xDistance)));
  kTemp += ((p0.xDistance-p6.xDistance)*(p0.yDistance-p1.yDistance))
         - ((p0.yDistance-p6.yDistance)*(p0.xDistance-p1.xDistance));

  newPlane.i = iTemp / 6.0;
  newPlane.j = jTemp / 6.0;
  newPlane.k = kTemp / 6.0;

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function will take in a string and a boolean value, parse the string to
 * get out a float value and the boolean to decide how to parse the string.
 *
 * @param[in] line - the line we want the value from.
 * @param[in] isZ - boolean value tha indicates if we are extracting a z value. 
 * @param[out] val - the value we are trying to extract from the line.
 * 
***************************************************************//*************/
float getValue ( string &line, bool isZ )
{

  bool isNeg = false;
  int space;
  int right;
  int rightOfRadixStart = 0;
  float devisor = 1.0;
  float left;
  float val;
  string desiredVal = line;
  string rightOfRadix;
  string leftOfRadix;  

  if ( line.find ( "-" ) == 0 )
    isNeg = true;

  if ( !isZ )
  {

    space = line.find ( " " );
    desiredVal = line.substr ( 0, space );
    line = line.substr ( space + 1 );

  }
  
  if ( isNeg)
    rightOfRadixStart = 1;
  rightOfRadix = desiredVal.substr ( rightOfRadixStart, desiredVal.find ( "." ) );
  leftOfRadix = desiredVal.substr ( desiredVal.find ( "." ) + 1 );
  
  for ( int i = 0; i < leftOfRadix.length (); i++ )
    devisor *= 10;

  right = atoi ( rightOfRadix.c_str() );
  left = atoi ( leftOfRadix.c_str() );
  left = left / devisor;

  val = right;
  val += left;

  if ( isNeg )
    val *= -1;

  return val;

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Determines if a given possible object is indeed an object if so we mark it 
 * and move on.
 *
 * @param[in] image - the xyz values of the pointcloud stream 
 * @param[in] row - the row the possible object is at.
 * @param[in] col - the column the possible object is at.
 * @param[out] false - the object is not an object or isn't of concern.
 * @param[out] true - the object is of concern.
***************************************************************//*************/
bool isObject ( vector < vector < point > > &image, int row, int col )
{
  float angleBetweenPlanes;
  plane objectPlane;
  int foundObjectsListLength = foundObjects.size();
  
  if (foundObjectsListLength > 200)
    foundObjects.erase (foundObjects.begin(), foundObjects.begin()+100); // ensure we don't have an infinitely large vector

  // ensure we won't overstep bounds
  
  if ( (row + 3) < 640 && (col + 3) < 240 && isValidPoint(image[row + 2][col + 2]) && isValidPoint(image[row + 1][col + 1]) &&
      isValidPoint(image[row + 2][col + 1]) && isValidPoint(image[row + 2][col + 3])&& isValidPoint(image[row + 1][col + 3]) &&
      isValidPoint(image[row + 3][col + 1]) && isValidPoint(image[row + 3][col + 3]))
  {
    getPlane (objectPlane, image[row + 2][col + 2], image[row + 1][col + 1], image[row + 2][col + 1],
              image[row + 2][col + 3], image[row + 1][col + 3], image[row + 3][col + 1], image[row + 3][col + 3]);
  }
  else if ( (row + 2) < 640 && (col + 2) < 240 && isValidPoint(image[row + 1][col + 1]) && isValidPoint(image[row][col]) &&
      isValidPoint(image[row + 1][col]) && isValidPoint(image[row + 1][col + 2])&& isValidPoint(image[row][col + 2]) &&
      isValidPoint(image[row + 2][col]) && isValidPoint(image[row + 2][col + 2]))
  {
    getPlane (objectPlane, image[row + 1][col + 1], image[row][col], image[row + 1][col],
              image[row + 1][col + 2], image[row][col + 2], image[row + 2][col], image[row + 2][col + 2]);
  }
  else
    return false; // object is too small and out of the way to be of concern

  for (int iter = 0; iter < foundObjectsListLength; iter++)
  {
    if ( sameObject (foundObjects[iter], image[row][col]) )
      return false;
  }

  angleBetweenPlanes = findAngle ( objectPlane );

  if ( angleBetweenPlanes < maxAngle )
    return false;

  foundObjects.push_back (image[row][col]);
  return true;

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function will read the image point by point into a 2D Vector Array. So
 * we can use the points later on.
 *
 * @param[in] fin - The input file stream of the pcd data, will be removed. 
 * @param[in] image - The vector we are reading the image into
 * 
 * TODO: Change from file stream to message
***************************************************************//*************/
void readImage ( const std_msgs::Float32MultiArray::ConstPtr &msg, vector < vector < point > > &image )
{
  int i = 0;
  int j;
  vector < point > imageRow;
  point currPoint;
  
  vector<float>::const_iterator it = msg->data.begin();
  
  while (i < 240)
  {
    for (j = 0; j < 640; j++ && it != msg->data.end())
    {
      if ( (j + 1) % 3 == 1 )
        currPoint.xDistance = *it;
      if ( (j + 1) % 3 == 2 )
        currPoint.yDistance = *it;
      if ( (j + 1) % 3 == 0 )
      {
        currPoint.zDistance = *it;
        imageRow.push_back(currPoint);
      }
      it++;
    }
    image.push_back(imageRow);
    imageRow.clear();
    i++;
  }
  
  
  /*for (i = 0; i < 240; i++)
  {
    for (j = 0; j < 640; j++)
    {
      // push each point onto a vector
      //readRow (msg, currPoint); // read in to the current point 
      imageRow.push_back(currPoint);
    }
    //push each vector onto the image
    image.push_back(imageRow); // add the row to the image
    imageRow.clear(); // clear the row
  }*/
  
}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function will use the open input file stream and point structure and
 * then read in a single row and return the x, y and z values using the point
 * structure that we passed in.
 *
 * @param[in] objectPlane - the plane of the object we are checking against. 
 * @param[out] angle - the angle between the object and the drive plane
 * 
 * TODO: change file input to ros message
***************************************************************//*************/
void readRow ( string &msg, point &newPoint )
{
 
  string line;
  string xWhole;
  string xDec;
  string yWhole;
  string yDec;
  string zWhole;
  string zDec;
  float x;
  float y;
  float z;

  //getline ( fin, line ); // read in a single line of the msg string
  readline (msg, line);
 
  if ( line == "nan nan nan" )
  {
    newPoint.xDistance = 0;
    newPoint.yDistance = 0;
    newPoint.zDistance = 0;
  }
 
  else
  {
    newPoint.xDistance = getValue ( line, false );
    newPoint.yDistance = getValue ( line, false );
    newPoint.zDistance = getValue ( line, true );
  }

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Removes a single line from a message and then saves that line and the new 
 * message
 *
 * @param[in] msg - The message we are looking for strings in
 * @param[in] line - The line we want to return
 * 
***************************************************************//*************/
void readline ( string &msg, string &line )
{
  int pos = msg.find("\n");

  line = msg.substr(0, pos);
  msg = msg.substr(pos+1, msg.length());

}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * Determines if we have already found an object at that point by checking the
 * previously found objects
 *
 * @param[in] found - The point that has already been found. 
 * @param[in] currPoint - The point we are checking against
 * 
***************************************************************//*************/
bool sameObject ( point found, point currPoint)
{
  if (currPoint.xDistance > (found.xDistance + .5) || currPoint.xDistance > (found.xDistance - .5) )
    return true;
  if (currPoint.yDistance > (found.yDistance + .5) || currPoint.yDistance > (found.yDistance - .5) )
    return true;
  if (currPoint.zDistance > (found.zDistance + .5) || currPoint.zDistance > (found.zDistance - .5) )
    return true;
  
  return false;
}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function takes the depth image vector and the row and column that has
 * been flagged as a possible object. We will then find the object's plane and 
 * decide if it is an obsticle we need to avoid.
 *
 * @param[in] image - the xyz image from the pointcloud 
 * @param[in] currRowCol - the current row and column we are looking at
 * @param[in] currPos - an iterator of the current position we are at
***************************************************************//*************/
bool scanArea (vector < vector < point > > &image, rowcol currRowCol, list<rowcol>::iterator currPos)
{
  int row = currRowCol.row;
  int column = currRowCol.col;
  
  
  if ( (row - 5) < 0)
  {
    row += 5;
  }
  if ( (row + 4) >= 640)
  {
    row -= 4;
  }
  if ( (column - 5) < 0)
  {
    column += 5;
  }
  if ( (column + 4) > 240)
  {
    column - 4;
  }

  for (int i = (row - 5); i < (row + 4); i++)
    for (int j = (column - 5); j < (column + 4); j++)
    {
      // check if object is within a 50 cm range should be same object
      if ( image [i][j].zDistance >= (image[row][column].zDistance - .50) &&
           image [i][j].zDistance <= (image[row][column].zDistance + .50))
      {
	// find object plane and decide how we should avoid it
        if ( isObject ( image, i, j ) )
        {
          // write the X and Z Distances to a ROS topic
          // add the i and j to the trouble area list, will need to update 
	  std::stringstream ss;
	  ss << "x: " << image[i][j].xDistance << " z: " << image[i][j].zDistance;
	  ROS_INFO("x: [%f] z: [%f]", image[i][j].xDistance, image[i][j].zDistance);
	  
	  std_msgs::String forward;
          forward.data = ss.str();
	  
	  DetectObjStream_pub.publish(forward);
          /*cout << "I found an object at (" << image [i][j].xDistance << ", "
               << image[i][j].yDistance << ", " << image[i][j].zDistance << ")" << endl;*/
          // update the location of the object in _lastSweep
          return true;
        }
      }
    }

  return false;
}

/******************************************************************************
 * @author Samuel Carroll
 *
 * @par Description:
 * This function will take in an integer from the scanRow globals, scan a row
 * and update the scanRow global it was passed, then it will return any 
 * trouble areas in the current image so we can look at them in the next image
 *
 * @param[in] image - the vector that holds the image. 
 * @param[in] row - the row we are currently scanning
 * @param[in] goLeft - a counter for the objects to our right
 * @param[in] goRight - a counter for the objects to our left
 * 
 * TODO: Remove the goLeft and goRight counters no longer handled here.
***************************************************************//*************/
void scanRows (vector < vector < point > > &image, int row, int &goLeft, int &goRight)
{
  int j;
  rowcol currRowCol;

  for (j = 0; j < 640; j ++ ) // scan the row we are at
  {
    // ignore if the zDistance is zero since that is a nan value
    if (image[row][j].zDistance < MINDIST && image[row][j].zDistance != 0)
    {
      currRowCol.row = row;
      currRowCol.col = j;
      if (_currSweep.size() == 0 || (_currSweep.back().col > j + 20 ||
          _currSweep.back().col < 20)) // ignore a certain amout that should be object space
        _currSweep.push_back(currRowCol);
    }
  }

}

bool isValidPoint (point checkPoint)
{
  if (checkPoint.xDistance != checkPoint.xDistance)
    return false;
  if (checkPoint.yDistance != checkPoint.yDistance)
    return false;
  if (checkPoint.zDistance != checkPoint.zDistance)
    return false;
  return true;
}
