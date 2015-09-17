Once the OpenNI2 package is installed on your computer. You will need to get
the /camera/depth/points to a human readable format.

To do so ensure that we have the api, common_msgs, and ros_comm in your 
workspace. Then you will also need the nodelet_core, geometry_experimental,
and perception_pcl to be in the workspace and catkin_make.

Once this has built start up OpenNI2 with the following command
$ roslaunch openni2_launch openni2.launch

Once OpenNI2 is running use the following command to take the output from
/camera/depth/points to the needed format, this is handled by perception_pcl
Use the following command to output to a file.
$ rosrun pcl_ros pointcloud_to_pcd input:=/camera/depth/points

If you open any of the .pcd file you just made you should have something like
this.
# .PCD v0.7 - Point Cloud Data file format
VERSION 0.7
FIELDS x y z
SIZE 4 4 4
TYPE F F F
COUNT 1 1 1
WIDTH 640
HEIGHT 480
VIEWPOINT 0 0 0 1 0 0 0
POINTS 307200
DATA ascii
-1.1817002 -0.88486612 2.1430001
-1.1779428 -0.88486612 2.1430001

The first 11 lines are just header information, the rest of the lines should
be distances, they start in the upper left corner of the image and move to 
the positive x, then move to the positive y (up is negative y), then we have the z value. All of these measurements are in meters.

To Do:
Drop all y values less than 0.
Identify safe to travel zone. Where is safe to drive.
	(this will be the hard part)
Look for local extremes (what has gotten too close to us?)
