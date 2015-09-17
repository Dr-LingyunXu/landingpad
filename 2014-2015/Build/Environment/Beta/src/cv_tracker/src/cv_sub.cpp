#include "ros/ros.h"
#include "image_transport/image_transport.h"
#include "opencv2/highgui/highgui.hpp"
#include "cv_bridge/cv_bridge.h"

using namespace cv;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    imshow("view", cv_bridge::toCvShare(msg, "bgr8")->image);
    if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
           return; 
        }
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle nh;
  namedWindow("view");
  startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("CVCam", 1, imageCallback);
  ros::spin();
  destroyWindow("view");
}
