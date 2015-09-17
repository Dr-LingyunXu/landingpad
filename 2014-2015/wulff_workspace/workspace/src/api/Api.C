/*************************************************************************//**
 * @file Api.C 
 *
 * @brief SOURCE - main file.
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
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/NavSatFix.h"
#include "sensor_msgs/NavSatStatus.h"
#include "sensor_msgs/PointCloud.h"
#include "sensor_msgs/Temperature.h"
#include <pthread.h>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

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
/*  pthread_create(&THREADS[1], NULL, CreateMessage, (void*) "Chatter", (void*) msg->data);
  pthread_join(thread_handles[1], NULL);
*/
  ROS_INFO("Heard: [%s] on Chatter", msg->data.c_str());
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
/*  pthread_create(&THREADS[4], NULL, CreateMessage, (void*) "GPS", (void*) msg->data);
  pthread_join(thread_handles[4], NULL);*/

  ROS_INFO("Heard: [%s] on GPS", msg->data.c_str());
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
/*  pthread_create(&THREADS[0], NULL, CreateMessage, (void*) "Error", (void*) msg->data);
  pthread_join(thread_handles[0], NULL);*/

  ROS_INFO("Heard: [%s] on Error", msg->data.c_str());
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
/*  pthread_create(&THREADS[8], NULL, CreateMessage, (void*) "Other", (void*) msg->data);
  pthread_join(thread_handles[8], NULL);*/

  ROS_INFO("I heard: [%s] on Other Callback", msg->data.c_str());
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
/*  pthread_create(&THREADS[2], NULL, CreateMessage, (void*) "Cam", (void*) msg->data);
  pthread_join(thread_handles[2], NULL);*/

  ROS_INFO("Heard: [%s] on Cam", msg->data.c_str());
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
/*  pthread_create(&THREADS[3], NULL, CreateMessage, (void*) "CV", (void*) msg->data);
  pthread_join(thread_handles[3], NULL);*/

  ROS_INFO("Heard: [%s] on CV", msg->data.c_str());
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
/*  pthread_create(&THREADS[5], NULL, CreateMessage, (void*) "Motor", (void*) msg->data);
  pthread_join(thread_handles[5], NULL);*/

  ROS_INFO("Heard: [%s] on Motor", msg->data.c_str());
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
/*  pthread_create(&THREADS[6], NULL, CreateMessage, (void*) "Slams", (void*) msg->data);
pthread_join(thread_handles[6], NULL);*/

  ROS_INFO("Heard: [%s] on Slams", msg->data.c_str());
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
/*  pthread_create(&THREADS[7], NULL, CreateMessage, (void*) "Sim", (void*) msg->data);
pthread_join(thread_handles[7], NULL);*/

  ROS_INFO("Heard: [%s] on Sim", msg->data.c_str());
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Main thread to set up call backs and link topic names as static strings.
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/
int main(int argc, char **argv)
{

  //THREADS = malloc (THREADCOUNT * sizeof(pthread_t));

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
  ros::init(argc, argv, "APINode");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n,n1,n2;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
  ros::Subscriber sub0 = n.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber sub1 = n.subscribe("Error", 1000, ErrorCallback);
  ros::Subscriber sub2 = n.subscribe("GPSStream", 1000, GPSCallback);
  ros::Subscriber sub3 = n.subscribe("Other", 1000, OtherCallback);
  ros::Subscriber sub4 = n.subscribe("CamStream", 1000, CamCallback);
  ros::Subscriber sub5 = n.subscribe("SlamStream", 1000, SlamCallback);
  ros::Subscriber sub6 = n.subscribe("SimStream", 1000, SimCallback);
  ros::Subscriber sub7 = n.subscribe("CVStream", 1000, CVCallback);
  ros::Subscriber sub8 = n.subscribe("MotorStream", 1000, MotorCallback);

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * This is a stub left in case we feel the urge to try and get pthreading up.
 *
 * @param[in] caller - generic ptr to string representing the messinger.
 * @param[in] msg - generic ptr to string for the message.
 *
 *****************************************************************************/

/*void* CreateMessage(void * caller, void * msg)
{
  string tell = (string) msg;
  string teller = (string) caller;

  ROS_INFO("Api heard: %s from %s", msg->data.c_str());
}*/
