/* Node to tell if the UGV has reached its current destination. */
#include <iostream>
#include <cstdlib>

//ROS
#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char* argv[])
{
    double goal_long, goal_lat, current_long, current_lat;
    double threshold = 0.00001;
    std_msgs::String message;
    
    goal_long = atof(argv[1]);
    goal_lat = atof(argv[2]);
    
    /**
    * From: ROSTutorialsWritingPublisherSubscriber(c++)
    * At: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
    * 
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
    * From: ROSTutorialsWritingPublisherSubscriber(c++)
    * At: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
    * 
    * NodeHandle is the main access point to communications with the ROS system.
    * The first NodeHandle constructed will fully initialize this node, and the last
    * NodeHandle destructed will close down the node.
    */
    ros::NodeHandle n;
    
    /**
    * From: ROSTutorialsWritingPublisherSubscriber(c++)
    * At: http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
    * 
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
    ros::Publisher arrived_waypoint_pub = n.advertise<std_msgs::String>("arrived_waypoint", 1000);

    //runs until ROS shutdown command received
    while(ros::ok())
    {
        //need to be able to get next goal waypoint
        
        //need to get the current gps coordinates
        
        if(abs(goal_lat - current_lat) < threshold && abs(goal_long - current_long) < threshold)
        {
            msg = "Waypoint reached: True";
        }
        else
        {
            msg = "Waypoint reached: False";
        }
        //set the standard message object's data field
        message.data = msg;
        //publish the message
        arrived_waypoint_pub.publish(message);
    }
}