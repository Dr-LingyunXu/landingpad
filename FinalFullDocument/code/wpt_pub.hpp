/***************************************************************************//**
* \file wpt_pub.hpp
*
* \brief ROS Implementation of a waypoint publisher (header)
* \author Christopher J Smith
* \date February 08, 2013
*
* Waypoint publisher for the landing pad project
*
******************************************************************************/

#ifndef _wpt_pub_hpp_
#define _wpt_pub_hpp_

#include <ros/ros.h>
#include <ros/rate.h>
#include <tf/tf.h>
#include <string>

#include <boost/thread.hpp>

#include <geometry_msgs/Pose.h>

//waypoint.cpp header files in mavros file
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointSetCurrent.h>
#include <mavros_msgs/WaypointClear.h>
#include <mavros_msgs/WaypointPull.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/CommandTOL.h>
#include <mavros_msgs/SetMode.h>

namespace wpt_pub
{
	class WPTPUB
	{
	public:
		WPTPUB( const ros::NodeHandle &_nh,
				const ros::NodeHandle &_nh_priv);

		~WPTPUB();
	private:
		void spin();
		void spinOnce();
		void deg_to_min();
		void read_file();
		void startpos(const geometry_msgs::PoseStamped::ConstPtr& msg);

		ros::NodeHandle nh;
		ros::NodeHandle nh_priv;
		std::string frame_id;
		std::string wpt_file;
		boost::mutex cmd_lock;


		geometry_msgs::Pose pose;

		ros::Subscriber sub;

		ros::Rate spin_rate;
		boost::thread spin_thread;
		
		mavros_msgs::CommandTOL cmd;
		std::vector<mavros_msgs::CommandTOL> cmds;

		mavros_msgs::Waypoint waypt;
		std::vector<mavros_msgs::Waypoint> wpts;

		bool first_spin;

		ros::Publisher wpt_pub;
		ros::Subscriber pos_sub;

	};

}
#endif