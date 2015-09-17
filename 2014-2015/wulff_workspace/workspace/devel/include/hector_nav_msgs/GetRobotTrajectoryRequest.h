/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/hector_slam/hector_nav_msgs/srv/GetRobotTrajectory.srv
 *
 */


#ifndef HECTOR_NAV_MSGS_MESSAGE_GETROBOTTRAJECTORYREQUEST_H
#define HECTOR_NAV_MSGS_MESSAGE_GETROBOTTRAJECTORYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hector_nav_msgs
{
template <class ContainerAllocator>
struct GetRobotTrajectoryRequest_
{
  typedef GetRobotTrajectoryRequest_<ContainerAllocator> Type;

  GetRobotTrajectoryRequest_()
    {
    }
  GetRobotTrajectoryRequest_(const ContainerAllocator& _alloc)
    {
    }






  typedef boost::shared_ptr< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetRobotTrajectoryRequest_

typedef ::hector_nav_msgs::GetRobotTrajectoryRequest_<std::allocator<void> > GetRobotTrajectoryRequest;

typedef boost::shared_ptr< ::hector_nav_msgs::GetRobotTrajectoryRequest > GetRobotTrajectoryRequestPtr;
typedef boost::shared_ptr< ::hector_nav_msgs::GetRobotTrajectoryRequest const> GetRobotTrajectoryRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hector_nav_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/home/cracker/workspace/src/common_msgs/nav_msgs/msg', '/home/cracker/workspace/devel/share/nav_msgs/msg'], 'geometry_msgs': ['/home/cracker/workspace/src/common_msgs/geometry_msgs/msg'], 'actionlib_msgs': ['/home/cracker/workspace/src/common_msgs/actionlib_msgs/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hector_nav_msgs/GetRobotTrajectoryRequest";
  }

  static const char* value(const ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
";
  }

  static const char* value(const ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct GetRobotTrajectoryRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::hector_nav_msgs::GetRobotTrajectoryRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // HECTOR_NAV_MSGS_MESSAGE_GETROBOTTRAJECTORYREQUEST_H
