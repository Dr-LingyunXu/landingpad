/*************************************************************************//**
 * @file GPS.C 
 *
 * @brief SOURCE - GPS file.
 *
 * @mainpage ROS API
 *
 * @section course_section CSC 465
 *
 * @author Alex Wulff
 *
 * @date December 15, 2014
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
 * This API for ROS node communication is developed for ease of subscription 
 * for topics on custom nodes.  This will assist in the completion of the UGV/
 * UAV project for which we were all indroctinated.  This was heavily borrowed
 * from http://wiki.ros.org/ROS/Tutorials.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      (Linux) - catkin_make
 *
 * @par Usage:
 @verbatim
 rosrun api Api
 @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date              Modification
 ----------------  --------------------------------------------------------------
 * December 15, 2014	Thought about an API.
 *
 * January 1-14, 2015	Created archtype and initial documentation.
 *
 * January 22, 2015	Began cross access of topics.
 *
 * January 29, 2015	Was advised to subdivide the API into each topic set then
 *                      rebuild the base.
 *
 * February 2-5, 2015   Rebuilt structure and started debugging.
 *
 * February 8, 2015	Finished base structure and added documentation.
 *
 @endverbatim
 *
 ******************************************************************************/

/******************************************************************************
 *
 * INCLUDE
 *
 ******************************************************************************/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sys/time.h>

/******************************************************************************
 *
 * GLOBALS
 *
 ******************************************************************************/

ros::Publisher gpsStream_pub;

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for gps consolidation.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/
void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  // transmit out
//  ROS_INFO("GPS heard: [%s]", msg->data.c_str());

//  ros::NodeHandle gps;
//  gpsStream_pub = gps.advertise<std_msgs::String>("GPSStream", 1000);

/*  std::stringstream ss;
  ss << msg->data.c_str();
  ss << " received at ";
  ss << (time(NULL));
  
  std_msgs::String forward;
  forward.data = ss.str();*/

  // Forward to Main API
  gpsStream_pub.publish(msg);//forward);
  ros::spinOnce();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Setup for middleman that is the gps node.
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/
int main(int argc, char **argv)
{
  // GPS Conversions
  ros::init(argc, argv, "GPS");

  ros::NodeHandle gps;

  // publisher
  gpsStream_pub = gps.advertise<sensor_msgs::NavSatFix>("GPSStream", 1000);

  // subscribe
  ros::Subscriber sub = gps.subscribe("GPSData", 1000, gpsCallback);
//  ros::Rate loop_rate(10);

/*  // test publish
  ros::Publisher chatter_pub = gps.advertise<std_msgs::String>("chatter", 1000);

  int count = 0;
  while (ros::ok())
  {
    **
     * This is a message object. You stuff it with data, and then publish it.
     *
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    **
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     *
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }*/


  // Listen mode
  // wait for stuff
  ros::spin();
  

  return 0;
}
