/*************************************************************************//**
 * @file CV.C 
 *
 * @brief SOURCE - cv file.
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

/******************************************************************************
 *
 * GLOBALS
 *
 ******************************************************************************/

ros::Publisher CVStream_pub;

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Callback for CV data consolidation.
 *
 * @param[in] msg - the message being sent down the topic. 
 *
 *****************************************************************************/

void CVCallback(const std_msgs::String::ConstPtr& msg)
{
  // transmit out
  ROS_INFO("I heard: [%s]", msg->data.c_str());

  std::stringstream ss;
  ss << msg->data.c_str();
  ss << " received at ";
  ss << (time(NULL));

  std_msgs::String forward;
  forward.data = ss.str();

  // Forward to Main API
  CVStream_pub.publish(forward);
  ros::spinOnce();
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Setup for middleman that is the cv node.
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/

int main(int argc, char **argv)
{
  // Slam Conversions
  ros::init(argc, argv, "CV");

  ros::NodeHandle cv;

  // publisher
  CVStream_pub = cv.advertise<std_msgs::String>("CVStream", 1000);

  // subscribe
  ros::Subscriber sub = cv.subscribe("CVData", 1000, CVCallback);

  // wait for stuff
  ros::spin();

  return 0;
}
