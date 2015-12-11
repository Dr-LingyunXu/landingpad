#include <wpt_pub/wpt_pub.hpp>

#include <ros/ros.h>
#include <cstdlib>

/*!
* \brief Main Function
*
* \author Chris Smithn
*
* Initializes ROS, instantiates the node handle for the waypoint publisher to use and
* instantiates the wpt_pub class.
*
* \param argc Number of command line arguments
* \param argv 2D character array of command line arguments
*
* \returns EXIT_SUCCESS, or an error state
*/
int main( int argc, char *argv[] )
{
	ros::init( argc, argv, "wpt_pub_node" );

	ros::NodeHandle nh;
	ros::NodeHandle nh_priv( "~" );


	wpt_pub::WPTPUB wptpub( nh, nh_priv);

	ros::spin( );

	std::exit( EXIT_SUCCESS );
}
