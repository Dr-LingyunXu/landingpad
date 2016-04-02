#include "wpt_pub/wpt_pub.hpp"
#include <string>
#include <ros/time.h>
#include <tf/tf.h>
#include <fstream>

namespace wpt_pub
{
	WPTPUB::WPTPUB(  const ros::NodeHandle &_nh,
				const ros::NodeHandle &_nh_priv ):
		//Parameters set at initialization of class
		nh(_nh),
		nh_priv(_nh_priv),
		frame_id("landingpad/uav/wpt_pub"),
		wpt_file("wpt_file"),
		spin_rate( 100 ),
		spin_thread( &WPTPUB::spin, this ),
		first_spin(true)
	{
		cmd_lock.unlock();
		nh_priv.param("frame_id", frame_id, (std::string)"landingpad/uav/wpt_pub");
		sub = nh.subscribe("/iris/ground/truth/pose", 1000, &WPTPUB::startpos, this);
		read_file();
	}

	WPTPUB::~WPTPUB()
	{
		spin_thread.interrupt();
	}

	void WPTPUB::startpos( const geometry_msgs::PoseStamped::ConstPtr& msg)
	{
		static int count = 0;
		if(count++%50 != 0)
			return;

		pose = msg->pose;
		ROS_INFO("Received pose information from simulation");
	}
	
	void WPTPUB::read_file()
	{
		int seq, is_curr, frame, command, auto_cont;
		double params[4], lat, lon, alt;

		std::ifstream fin;
		//fin.open(wpt_file.c_str());
		
		while( fin >> seq >> is_curr >> frame >> command >> 
				params[0] >> params[1] >> params[2] >> params[3] >>
				lat >> lon >> alt >> auto_cont)
		{
			command = 1;
			if( command == 16)
			{
				waypt.is_current = bool(is_curr);
				waypt.frame = frame;
				waypt.command = command;
				waypt.param1 = params[0];
				waypt.param2 = params[1];
				waypt.param3 = params[2];
				waypt.param4 = params[3];
				waypt.x_lat = lat;
				waypt.y_long = lon;
				waypt.z_alt = alt;
				waypt.autocontinue = bool(auto_cont);
				wpts.push_back(waypt);
			}
			else //Assuming command column is either Takeoff or Land command
			{
				cmd.request.min_pitch = 0;
				cmd.request.yaw = 0;
				cmd.request.latitude = pose.position.x;
				cmd.request.longitude = pose.position.y;
				cmd.request.altitude = 1.5;
				cmds.push_back(cmd);
				ROS_ERROR("COMMAND PUSHED INTO VECTOR");
			}

		}
		cmd.request.min_pitch = 0;
				cmd.request.yaw = 0;
				cmd.request.latitude = pose.position.x;
				cmd.request.longitude = pose.position.y;
				cmd.request.altitude = 1.5;
				cmds.push_back(cmd);
				ROS_ERROR("COMMAND PUSHED INTO VECTOR");
	}
	void WPTPUB::spin()
	{
		while( ros::ok())
		{
			boost::this_thread::interruption_point();
			spinOnce();
			spin_rate.sleep();
		}
	}
	void WPTPUB::spinOnce()
	{
		cmd_lock.lock();
		if(first_spin)
		{
			first_spin = false;

			//Set Guided Mode
			ros::ServiceClient cl = nh.serviceClient<mavros_msgs::SetMode>("/mavros/set_mode");
    		mavros_msgs::SetMode srv_setMode;
    		srv_setMode.request.base_mode = 0;
    		srv_setMode.request.custom_mode = "GUIDED";
    		if(cl.call(srv_setMode))
        		ROS_ERROR("setmode send ok %d value:", srv_setMode.response.success);
    		else
    		{
        		ROS_ERROR("Failed SetMode");
        		first_spin = true;
    		}

    		//Arm Device in simulation
    		ros::ServiceClient arming_cl = nh.serviceClient<mavros_msgs::CommandBool>("/mavros/cmd/arming");
    		mavros_msgs::CommandBool srv;
    		srv.request.value = true;
    		if(arming_cl.call(srv))	
        		ROS_ERROR("ARM send ok %d", srv.response.success);
    		else
    		{
      			ROS_ERROR("Failed arming or disarming");
    			first_spin = true;
    		}

    		//Request Takeoff
    		ros::ServiceClient takeoff_cl = nh.serviceClient<mavros_msgs::CommandTOL>("/mavros/cmd/takeoff");
    		if(takeoff_cl.call(cmds[0]))
    			ROS_ERROR("srv_takeoff send ok %d", cmds[0].response.success);
    		else
    		{
    			ROS_ERROR("Failed Takeoff");
    			first_spin = true;
    				
			}
		}
		cmd_lock.unlock( );
	}
}