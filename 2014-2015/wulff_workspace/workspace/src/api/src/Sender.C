/*************************************************************************//**
 * @file Sender.C 
 *
 * @brief SOURCE - sender file.
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
#include <sstream>

/******************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * Setup for spammer to test each topic as added to each node and the master,
 * API.C.
 *
 * @param[in] argc - count of args.
 * @param[in] argv - arguments themselves.
 *
 *****************************************************************************/

int main(int argc, char **argv)
{
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
//  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher gps_pub = n.advertise<std_msgs::String>("GPSData", 1000);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher error_pub = n.advertise<std_msgs::String>("Error", 1000);
  ros::Publisher sim_pub = n.advertise<std_msgs::String>("SimData", 1000);
  ros::Publisher cam_pub = n.advertise<std_msgs::String>("CamData", 1000);
  ros::Publisher cv_pub = n.advertise<std_msgs::String>("CVData", 1000);
  ros::Publisher motor_pub = n.advertise<std_msgs::String>("MotorData", 1000);
  ros::Publisher slam_pub = n.advertise<std_msgs::String>("SlamData", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);
    gps_pub.publish(msg);
    error_pub.publish(msg);
    sim_pub.publish(msg);
    slam_pub.publish(msg);
    cam_pub.publish(msg);
    motor_pub.publish(msg);
    cv_pub.publish(msg);


    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
