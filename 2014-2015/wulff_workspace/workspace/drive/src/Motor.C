#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <unistd.h>
#include "RoboteqDevice.h"
#include "ErrorCodes.h"
#include "Constants.h"


// GLOBAL SWITCH
  bool breakRun = 0;

void Velocity(double v)
{
  while (!breakRun)
  {
    // Presuming this is on ACM0.. will need to test with live hardware
    RoboteqDevice device;
    int status = device.Connect("/dev/ttyACM0");
    if(status != RQ_SUCCESS)
    {
      return;
    }
    // Running these on Chanel 1
    if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
      return;
    }

    //Wait 10 ms before sending another command to device
    sleepms(10);

    int result;
    if((status = device.GetConfig(_DINA, 1, result)) != RQ_SUCCESS)
    {
      return;
    }

    if((status = device.SetCommand(_GO, 1, v)) != RQ_SUCCESS)
    {
      return;
    }
  }
}

void Turn(double t)
{
  while (!breakRun)
  {
    // Presuming this is on ACM0.. will need to test with live hardware
    RoboteqDevice device;
    int status = device.Connect("/dev/ttyACM0");
    if(status != RQ_SUCCESS)
    {
      return;
    }
    // Running these on Chanel 2
    if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
      return;
    }

    //Wait 10 ms before sending another command to device
    sleepms(10);

    int result;
    if((status = device.GetConfig(_DINA, 1, result)) != RQ_SUCCESS)
    {
      return;
    }

    if((status = device.SetCommand(_GO, 2, t)) != RQ_SUCCESS)
    {
      return;
    }
  }
}

void ForwardLandingPad(double f)
{
  while (!breakRun)
  {
    // Presuming this is on ACM1.. will need to test with live hardware
    RoboteqDevice device;
    int status = device.Connect("/dev/ttyACM1");
    if(status != RQ_SUCCESS)
    {
      return;
    }
    // Running these on Chanel 1
    if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
      return;
    }

    //Wait 10 ms before sending another command to device
    sleepms(10);

    int result;
    if((status = device.GetConfig(_DINA, 1, result)) != RQ_SUCCESS)
    {
      return;
    }

    if((status = device.SetCommand(_GO, 1, f)) != RQ_SUCCESS)
    {
      return;
    }

  }
}

void LeftLandingPad(double l)
{
  while (!breakRun)
  {
// Presuming this is on ACM0.. will need to test with live hardware
    RoboteqDevice device;
    int status = device.Connect("/dev/ttyACM1");
    if(status != RQ_SUCCESS)
    {
      return;
    }
    // Running these on Chanel 1
    if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    {
      return;
    }

    //Wait 10 ms before sending another command to device
    sleepms(10);

    int result;
    if((status = device.GetConfig(_DINA, 1, result)) != RQ_SUCCESS)
    {
      return;
    }

    if((status = device.SetCommand(_GO, 1, l)) != RQ_SUCCESS)
    {
      return;
    }
  }
}


void Action(const std_msgs::String::ConstPtr& msg)
{
  std::string s = msg->data.c_str();
  // Parse given format decided with Hafiza and myself:
  // S - Steering left (negative) and right (positive) for X ticks (probably an int here would be ideal)
  // V - Velocity of Drive in RPM (negative being reverse)
  // LF - Landingpad Forward in radians
  // LL - Landingpad Left in radians
  // For example - S:-238,V:20,LF:0.03,LL:-0.1
  std::string speed, turn, landForward, landLeft;
  speed = s.substr(2 ,s.find(","));
  s = s.substr(s.find(",") + 1);
  turn = s.substr(2, s.find(","));
  s = s.substr(s.find(",") + 1);
  landForward = s.substr(3, s.find(','));
  s = s.substr(s.find(",") + 1);

  breakRun = 1;
  usleep(50);
  breakRun = 0;

  landLeft = s.substr(3);
  Velocity(atof(speed.c_str()));
  Turn(atof(turn.c_str()));
  ForwardLandingPad(atof(landForward.c_str()));
  LeftLandingPad(atof(landLeft.c_str()));

}


int main()
{
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("MotorStream", 10, Action);

  ros::spin();
  return 0;
}
