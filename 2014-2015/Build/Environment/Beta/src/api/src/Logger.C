#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/NavSatFix.h"
#include <algorithm>
#include <string> 

using namespace std;


string GetTime()
{
  time_t rawtime;
  struct tm * timeinfo;
  stringstream ss;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  ss << asctime(timeinfo);
  return ss.str();
}

void WritePic(string file, sensor_msgs::Image::ConstPtr msg)
{
  if (msg->encoding != "rgb8")
  {
     cout << "ERROR Bad image format: " << msg->encoding << endl;
     return;
  }
  ofstream fout;
  fout.open(file.c_str());

  fout <<  "P3" << endl;
  fout << msg->width << " " << msg->height;
  fout << "255" << endl;

  for ( uint32_t y = 0; y < msg->height; y++ )
  {
    for ( uint32_t x = 0; x < msg->width; x++ )
    {
      // Get indices for the pixel components
      uint32_t redByteIdx = y*msg->step + 3*x;
      uint32_t greenByteIdx = redByteIdx + 1;
      uint32_t blueByteIdx = redByteIdx + 2;

      fout << msg->data[ redByteIdx ] << " " <<
              msg->data[ greenByteIdx ] << " " <<
              msg->data[ blueByteIdx ];
    }
    fout << endl;
  }

  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for general chatter line.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.chatterLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for general gps line.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void GPSCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  ofstream fout; 
  fout.open("./api/Logs/.gpsLog", std::ofstream::app);
  fout << msg->latitude << ", " << msg->longitude << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for errors line.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void ErrorCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout; 
  fout.open("./api/Logs/.errorLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for other lines... Mostly for debugging.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void OtherCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.otherLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for general camera line.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void CamCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.camLog-";
  file += GetTime();
  WritePic(file, msg);
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for general CV datas.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void CVCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.cvLog-";
  file += GetTime();
  WritePic(file, msg);
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for general motor control line.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void MotorCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.motorLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for SLAM data feeds.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void SlamCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.slamLog-";
  file += GetTime();
  WritePic(file, msg);
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void SimCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.simLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void GPSDataCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.gpsTopLog", std::ofstream::app);
  fout << msg->latitude << ", " << msg->longitude << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void SimDataCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.simTopLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void CamDataCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.camTopLog-";
  file += GetTime();
  WritePic(file, msg);
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void CVDataCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.cvTopLog-";
  file += GetTime();
  WritePic(file, msg);
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void MotorDataCallback(const std_msgs::String::ConstPtr& msg)
{
  ofstream fout;
  fout.open("./api/Logs/.motorTopLog", std::ofstream::app);
  fout << msg->data << endl;
  fout.close();
}


/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for simulation data I/O.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void SlamDataCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  string file = "./api/Logs/.slamTopLog-";
  file += GetTime();
  WritePic(file, msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "LoggerNode");

  int runMode = 0; // default

  ros::NodeHandle n;

  ros::Subscriber s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14;

  if (runMode == 0 || runMode == 1)
  {
    s9 = n.subscribe("GPSData", 1000, GPSDataCallback);
    s10 = n.subscribe("SimData", 1000, SimDataCallback);
    s11 = n.subscribe("CamData", 1000, CamDataCallback);
    s12 = n.subscribe("CVData", 1000, CVDataCallback);
    s13 = n.subscribe("MotorData", 1000, MotorDataCallback);
    s14 = n.subscribe("SlamData", 1000, SlamDataCallback);
  }

  if (runMode == 0 || runMode == 2)
  {
    s2 = n.subscribe("GPSStream", 1000, GPSCallback);
    s3 = n.subscribe("Other", 1000, OtherCallback);
//    s4 = n.subscribe("CamStream", 1000, CamCallback);
    s4 = n.subscribe("/vrep/CameraStream", 1000, CamCallback);
    s5 = n.subscribe("SlamStream", 1000, SlamCallback);
    s6 = n.subscribe("SimStream", 1000, SimCallback);
    s7 = n.subscribe("CVStream", 1000, CVCallback);
    s8 = n.subscribe("MotorStream", 1000, MotorCallback);
  }

 if (runMode == 0 || runMode == -1)
 {
    s1 = n.subscribe("chatter", 1000, chatterCallback);
    s0 = n.subscribe("Error", 1000, ErrorCallback);
 }
  

  ros::spin();

  return 0;
}
