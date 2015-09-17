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
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/ros_comm/test/test_roscpp/test_serialization/msg/WithTime.msg
 *
 */


#ifndef TEST_ROSCPP_MESSAGE_WITHTIME_H
#define TEST_ROSCPP_MESSAGE_WITHTIME_H


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
struct WithTime_
{
  typedef WithTime_<ContainerAllocator> Type;

  WithTime_()
    : my_time()  {
    }
  WithTime_(const ContainerAllocator& _alloc)
    : my_time()  {
    }



   typedef ros::Time _my_time_type;
  _my_time_type my_time;




  typedef boost::shared_ptr< ::test_roscpp::WithTime_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_roscpp::WithTime_<ContainerAllocator> const> ConstPtr;

}; // struct WithTime_

typedef ::test_roscpp::WithTime_<std::allocator<void> > WithTime;

typedef boost::shared_ptr< ::test_roscpp::WithTime > WithTimePtr;
typedef boost::shared_ptr< ::test_roscpp::WithTime const> WithTimeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_roscpp::WithTime_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_roscpp::WithTime_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::test_roscpp::WithTime_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_roscpp::WithTime_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::WithTime_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::WithTime_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::WithTime_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::WithTime_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_roscpp::WithTime_<ContainerAllocator> >
{
  static const char* value()
  {
    return "60f189e40cfeaefbc79e6cdbd1605364";
  }

  static const char* value(const ::test_roscpp::WithTime_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x60f189e40cfeaefbULL;
  static const uint64_t static_value2 = 0xc79e6cdbd1605364ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_roscpp::WithTime_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_roscpp/WithTime";
  }

  static const char* value(const ::test_roscpp::WithTime_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_roscpp::WithTime_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time my_time\n\
";
  }

  static const char* value(const ::test_roscpp::WithTime_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_roscpp::WithTime_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.my_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct WithTime_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_roscpp::WithTime_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_roscpp::WithTime_<ContainerAllocator>& v)
  {
    s << indent << "my_time: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.my_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ROSCPP_MESSAGE_WITHTIME_H
