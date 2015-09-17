#include "ackerman_drive/ackerman_controller.h"
#include <cmath>

namespace ackerman_drive
{

    ackerman_drive::ackerman_drive(ros::NodeHandle &n) : n(n)
    {
        ros::NodeHandle nh("~");
        nh.param<double>("wheel_base", wheelBase, 0.9652);
        nh.param<double>("wheel_radius", wheelRadius, 0.3302);
        nh.param<std::string>("back_left", backLeft, "back_left");
        nh.param<std::string>("back_right", backRight, "back_right");
        nh.param<std::string>("steer_wheels", steerWheels, "steer_wheels");

        if (wheelBase <= 0)
        {
            ROS_WARN("wheel_base must be greater than zero");
            wheelBase = 0.9652;
        }
        if (wheelRadius <= 0)
        {
            ROS_WARN("wheel_radius must be greater than zero");
            wheelRadius = 0.3302;
        }

        sub = n.subscribe("cmd_vel",1, &ackerman_drive::callback, this);


        jointPub = n.advertise<trajectory_msgs::JointTrajectory>("cmd_joint_traj", 1);
	steerPub = n.advertise<trajectory_msgs::JointTrajectory>("cmd_steer_traj", 1);
    }

    ackerman_drive::~ackerman_drive()
    {
        sub.shutdown();
        jointPub.shutdown();
	steerPub.shutdown();
    }

    void ackerman_drive::callback(const geometry_msgs::Twist::ConstPtr& msg)
    {

        inverseAckermanDriveKinematics(msg->linear.x, msg->angular.z);
    }
    //Convert to velocity for each wheel in radians/second
    void ackerman_drive::inverseAckermanDriveKinematics(const double &linear_velocity, const double &angular_velocity) {

        trajectory_msgs::JointTrajectory driveCtrl;
        trajectory_msgs::JointTrajectoryPoint point;
	trajectory_msgs::JointTrajectory steering;
	trajectory_msgs::JointTrajectoryPoint steering_point;

        double phi_dot;//Left chanel velocity.
        double beta;//Right chanel Velocity.

        phi_dot = (linear_velocity / wheelRadius);

	double temp = wheelBase * angular_velocity;

	if(linear_velocity == 0)
		beta = 0.0;
	else
	{
		temp /= linear_velocity;
		if(temp > 1)
			temp = 1;
		else if(temp < -1)
			temp = -1;

        	beta = (asin(temp));
	}
	//Name the wheels and push on the velociteis for each.
        /*driveCtrl.joint_names.push_back(frontLeft);
        point.velocities.push_back(chL);
        driveCtrl.joint_names.push_back(frontRight);
        point.velocities.push_back(chR);*/
        driveCtrl.joint_names.push_back(backLeft);
        point.velocities.push_back(phi_dot);
        driveCtrl.joint_names.push_back(backRight);
        point.velocities.push_back(phi_dot);

	steering.joint_names.push_back(steerWheels);
	steering_point.velocities.push_back(beta);	


	driveCtrl.points.push_back(point);
	steering.points.push_back(steering_point);
		

        jointPub.publish(driveCtrl);
	steerPub.publish(steering);
    }
};

