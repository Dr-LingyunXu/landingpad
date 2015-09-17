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
 * @date February 22nd
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
 * This system tests reception of messages.  Specifically this was used for testing
 * Sam's PCD transfer.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      (Linux) - catkin_make
 *
 * @par Usage:
 @verbatim
 rosrun api ApiSender
 @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @par Modifications and Development Timeline:
 @verbatim
 Date              Modification
 ----------------  --------------------------------------------------------------
 * March 8th		Finished structure to test performance of sam's code
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
#include "sensor_msgs/PointCloud.h"
#include "geometry_msgs/Point32.h"
#include "sensor_msgs/ChannelFloat32.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <string.h>
#include <ros/console.h>

/******************************************************************************
 *
 * GLOBALS
 *
 ******************************************************************************/
sensor_msgs::PointCloud _PC;

void setupPCD();


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
//  ros::Publisher gps_pub = n.advertise<std_msgs::String>("GPSData", 1000);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher error_pub = n.advertise<std_msgs::String>("Error", 1000);
  ros::Publisher sim_pub = n.advertise<std_msgs::String>("SimData", 1000);
//  ros::Publisher cam_pub = n.advertise<std_msgs::String>("CamData", 1000);
//  ros::Publisher cv_pub = n.advertise<std_msgs::String>("CVData", 1000);
  ros::Publisher motor_pub = n.advertise<std_msgs::String>("MotorData", 1000);
  ros::Publisher slam_pub = n.advertise<sensor_msgs::PointCloud>("SlamData", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;

  setupPCD();

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
 //   gps_pub.publish(msg);
    error_pub.publish(msg);
    sim_pub.publish(msg);
//    slam_pub.publish(msg);
    slam_pub.publish(_PC);
 //   cam_pub.publish(msg);
    motor_pub.publish(msg);
//    cv_pub.publish(msg);
    

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

*/*****************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * this method sets up the image buffer for loading data as needed
 *
 * @param[in/out] buffer - character array representing picture.
 *
 *****************************************************************************/
void setupImage(char * buffer)
{
  char temp[256];
  int height, width, bitdepth;

  std::ifstream fin ("~/workspace/wulff_workspace/workspace/APISender/Image/snail.ascii.ppm");
  fin.getline(temp,256);
  fin >> width >> height >> bitdepth;
  int buffSize = height * width;
  buffer = new char [buffSize];
  for (int i = 0; i < buffSize ; i += 1)
  {
    fin >> buffer[i];
  }
}


/*void setupPCD()
{
  std::string buffer;
  int height, width, bitdepth;

//  std::ofstream fout ("~/workspace/wulff_workspace/workspace/APISender/roomMaze/values");

  std::ifstream fin ("/home/cracker/workspace/wulff_workspace/workspace/APISender/roomMaze/1425651050412133.pcd");

  geometry_msgs::Point32 insert;

  double size = 480 * 640;

  _PC.points.resize(size);
  
  while (getline(fin, buffer) && buffer.find("DATA") == -1)
  {
    if (buffer.find("WIDTH") != -1)
    {
      buffer = buffer.substr(buffer.find(" ") + 1);
      width = atoi(buffer.c_str());
    }

    if (buffer.find("HEIGHT") != -1)
    {
      buffer = buffer.substr(buffer.find(" ") + 1);
      height = atoi(buffer.c_str());
    }
  }

  // make pc space
  //geometry_msgs::Point32* pic;
  //pic = new geometry_msgs::Point32 [height * width];
  //_PC.points = new geometry_msgs::Point32 [height * width];

  int id = 0;
  // read actual data
  while (getline(fin, buffer))
  {
    // Sanity check
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    std::string temp = buffer.substr(0, buffer.find(" "));

    // X
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size())); 
//      insert.x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
      _PC.points[id].x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
      _PC.points[id].x = atoi(temp.c_str());
//      pic[id].x = atoi(temp.c_str());
//      insert.x = atoi(temp.c_str());
    }

    // Move down
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    buffer = buffer.substr(buffer.find(" "));

    // Y
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size()));
      _PC.points[id].y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      insert.y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
      _PC.points[id].y = atoi(temp.c_str());
//      pic[id].y = atoi(temp.c_str());
//      insert.y = atoi(temp.c_str());
    }

    // Move down
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    buffer = buffer.substr(buffer.find(" "));

    //Z
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size()));
      _PC.points[id].z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      insert.z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
      _PC.points[id].z = atoi(temp.c_str());
//      pic[id].z = atoi(temp.c_str());
//      insert.z = atoi(temp.c_str());
    }

  // DEBUG
//  ROS_DEBUG("Adding value: %s, %s, %s", pic[id].x, pic[id].y, pic[id].z);
//  fout << insert.x << " " << insert.y << " " << insert.z << std::endl;

//  _PC.points.push_back(insert);
  _PC.channels[id].name = "Testing";
//  _PC.channels[id].values.push_back(insert.z);

    // channel info
//    _PC.channels.name = "distance";
//    _PC.channels.values[id] = _PC.points[id].z;

//    id += 1;
  }
  
  // Set pic to PC
//  std::vector<geometry_msgs::Point32> temp (pic, pic + sizeof(pic) / sizeof(pic[0]));
//  _PC.points = temp;

  fin.close();
//  fout.close();
}
*/


/*****************************************************************************
 * @author Alex Wulff
 *
 * @par Description:
 * this method sets up the PCD like object we will be testing.
 *
 *
 *****************************************************************************/
 
void setupPCD()
{
  std::string buffer;
  int height, width, bitdepth;

//  std::ofstream fout ("~/workspace/wulff_workspace/workspace/APISender/roomMaze/values");

  std::ifstream fin ("/home/cracker/workspace/wulff_workspace/workspace/APISender/roomMaze/1425651050412133.pcd");

  if (!fin)
  {
    std::cout << "Bad input" << std::endl;
    exit(-1);
  }

  geometry_msgs::Point32 insert;
  //Point32 insert;
  
  while (getline(fin, buffer) && buffer.find("DATA") == -1)
  {
    if (buffer.find("WIDTH") != -1)
    {
      buffer = buffer.substr(buffer.find(" ") + 1);
      width = atoi(buffer.c_str());
    }

    if (buffer.find("HEIGHT") != -1)
    {
      buffer = buffer.substr(buffer.find(" ") + 1);
      height = atoi(buffer.c_str());
    }
  }

  // make pc space
  //geometry_msgs::Point32* pic;
  //pic = new geometry_msgs::Point32 [height * width];
  //_PC.points = new geometry_msgs::Point32 [height * width];

  int id = 0;
  // read actual data
  while (getline(fin, buffer))
  {
    // Sanity check
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    std::string temp = buffer.substr(0, buffer.find(" "));

    // X
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size()));
      insert.x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      _PC.points[id].x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].x = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
//      _PC->points[id].x = atoi(temp.c_str());
//      pic[id].x = atoi(temp.c_str());
      insert.x = atoi(temp.c_str());
    }

    // Move down
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    buffer = buffer.substr(buffer.find(" "));

    // Y
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size()));
//      _PC.points[id].y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
      insert.y = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
//      _PC->points[id].y = atoi(temp.c_str());
//      pic[id].y = atoi(temp.c_str());
      insert.y = atoi(temp.c_str());
    }

    // Move down
    if (buffer.find(" ") == -1)
    {
      std::cerr << "BAD FILE!" << std::endl;
      exit(-1);
    }

    buffer = buffer.substr(buffer.find(" "));

    //Z
    if (temp.find('.') != -1)
    {
      std::string temp2 = temp.substr(temp.find('.') + 1);
      double integer = atoi(temp.substr(0, temp.find('.')).c_str());
      bool negative = integer < 0;
      double fraction = atoi(temp2.c_str());
      // move down
      fraction = fraction / (pow(10, temp2.size()));
//      _PC.points[id].z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
//      pic[id].z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
      insert.z = negative ? integer + fraction : -1 * (abs(integer) + fraction);
    }

    else
    {
//      _PC->points[id].z = atoi(temp.c_str());
//      pic[id].z = atoi(temp.c_str());
      insert.z = atoi(temp.c_str());
    }

  // DEBUG
//  ROS_DEBUG("Adding value: %s, %s, %s", pic[id].x, pic[id].y, pic[id].z);
  //std::cout << insert.x << " " << insert.y << " " << insert.z << std::endl;

//  _PC.points.push_back(insert);
  _PC.points.push_back(insert);
    // channel info
//    _PC.channels.name = "distance";
//    _PC.channels.values[id] = _PC.points[id].z;

//    id += 1;
  }
  
  // Set pic to PC
//  std::vector<geometry_msgs::Point32> temp (pic, pic + sizeof(pic) / sizeof(pic[0]));
//  _PC.points = temp;

  fin.close();
//  fout.close();
}