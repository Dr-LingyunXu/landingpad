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
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/ros_comm/test/test_roscpp/test_serialization/msg/WithDuration.msg
 *
 */


#ifndef TEST_ROSCPP_MESSAGE_WITHDURATION_H
#define TEST_ROSCPP_MESSAGE_WITHDURATION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test_roscpp
{
template <class ContainerAllocator>
struct WithDuration_
{
  typedef WithDuration_<ContainerAllocator> Type;

  WithDuration_()
    : my_duration()  {
    }
  WithDuration_(const ContainerAllocator& _alloc)
    : my_duration()  {
    }



   typedef ros::Duration _my_duration_type;
  _my_duration_type my_duration;




  typedef boost::shared_ptr< ::test_roscpp::WithDuration_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_roscpp::WithDuration_<ContainerAllocator> const> ConstPtr;

}; // struct WithDuration_

typedef ::test_roscpp::WithDuration_<std::allocator<void> > WithDuration;

typedef boost::shared_ptr< ::test_roscpp::WithDuration > WithDurationPtr;
typedef boost::shared_ptr< ::test_roscpp::WithDuration const> WithDurationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_roscpp::WithDuration_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_roscpp::WithDuration_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_roscpp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rosgraph_msgs': ['/opt/ros/indigo/share/rosgraph_msgs/cmake/../msg'], 'test_roscpp': ['/home/cracker/workspace/src/ros_comm/test/test_roscpp/test/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/test_serialization/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/perf/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/perf_serialization/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_roscpp::WithDuration_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_roscpp::WithDuration_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::WithDuration_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::WithDuration_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::WithDuration_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::WithDuration_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_roscpp::WithDuration_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7ad52ba9d0229ba8b9c032400c77c367";
  }

  static const char* value(const ::test_roscpp::WithDuration_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7ad52ba9d0229ba8ULL;
  static const uint64_t static_value2 = 0xb9c032400c77c367ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_roscpp::WithDuration_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_roscpp/WithDuration";
  }

  static const char* value(const ::test_roscpp::WithDuration_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_roscpp::WithDuration_<ContainerAllocator> >
{
  static const char* value()
  {
    return "duration my_duration\n\
";
  }

  static const char* value(const ::test_roscpp::WithDuration_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_roscpp::WithDuration_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.my_duration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct WithDuration_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_roscpp::WithDuration_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_roscpp::WithDuration_<ContainerAllocator>& v)
  {
    s << indent << "my_duration: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.my_duration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ROSCPP_MESSAGE_WITHDURATION_H
