#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "ar_track_alvar_msgs/AlvarMarkers.h"

ros::Publisher pub;

void chatterCallback(const ar_track_alvar_msgs::AlvarMarkers::ConstPtr& msg)
{
	if(msg->markers.size() == 0)
		return;
	geometry_msgs::Pose pose;
	pose.position.x = msg->markers[0].pose.pose.position.x;
	pose.position.y = msg->markers[0].pose.pose.position.y;
	pose.position.z = msg->markers[0].pose.pose.position.z;

	pose.orientation.w = msg->markers[0].pose.pose.orientation.w;
	pose.orientation.x = msg->markers[0].pose.pose.orientation.x;
	pose.orientation.y = msg->markers[0].pose.pose.orientation.y;
	pose.orientation.z = msg->markers[0].pose.pose.orientation.z;

	pub.publish(pose);
}

int main(int argc, char** argv)
{

	ros::init(argc, argv, "listener");
	ros::NodeHandle n;
	pub = n.advertise<geometry_msgs::Pose>("pose", 1);
	ros::Subscriber sub = n.subscribe("ar_pose_marker", 1, chatterCallback);
	ros::spin();

	return 0;
}
