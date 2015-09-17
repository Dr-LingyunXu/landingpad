#ifndef __ACKERMAN_CONTROLLER__H__
#define __ACKERMAN_CONTROLLER__H__

#include "ros/ros.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "geometry_msgs/Twist.h"
#include <string.h>

namespace ackerman_drive
{

    class ackerman_drive
    {
        public:
            ackerman_drive(ros::NodeHandle &n);
            ~ackerman_drive();
            //void setWheelBase(double diameter);
            //void setRadius(double base);
            //double getWheelBase();
            //double getWheelDiameter();
            void callback(const geometry_msgs::Twist::ConstPtr& msg);

        private:
            ros::NodeHandle n;
            ros::Publisher jointPub; 
            ros::Subscriber sub;
	    ros::Publisher steerPub;
            double wheelBase;
            double wheelRadius;
	    /*std::string frontLeft;
	    std::string frontRight;*/
	    std::string backLeft;
	    std::string backRight;
	    std::string steerWheels;
            void inverseAckermanDriveKinematics(const double &linear_velocity, const double &angular_velocity); 
    };

};

#endif
