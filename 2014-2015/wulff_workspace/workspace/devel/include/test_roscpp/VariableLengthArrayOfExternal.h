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
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/ros_comm/test/test_roscpp/test_serialization/msg/VariableLengthArrayOfExternal.msg
 *
 */


#ifndef TEST_ROSCPP_MESSAGE_VARIABLELENGTHARRAYOFEXTERNAL_H
#define TEST_ROSCPP_MESSAGE_VARIABLELENGTHARRAYOFEXTERNAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <rosgraph_msgs/Log.h>

namespace test_roscpp
{
template <class ContainerAllocator>
struct VariableLengthArrayOfExternal_
{
  typedef VariableLengthArrayOfExternal_<ContainerAllocator> Type;

  VariableLengthArrayOfExternal_()
    : a()  {
    }
  VariableLengthArrayOfExternal_(const ContainerAllocator& _alloc)
    : a(_alloc)  {
    }



   typedef std::vector< ::rosgraph_msgs::Log_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosgraph_msgs::Log_<ContainerAllocator> >::other >  _a_type;
  _a_type a;




  typedef boost::shared_ptr< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> const> ConstPtr;

}; // struct VariableLengthArrayOfExternal_

typedef ::test_roscpp::VariableLengthArrayOfExternal_<std::allocator<void> > VariableLengthArrayOfExternal;

typedef boost::shared_ptr< ::test_roscpp::VariableLengthArrayOfExternal > VariableLengthArrayOfExternalPtr;
typedef boost::shared_ptr< ::test_roscpp::VariableLengthArrayOfExternal const> VariableLengthArrayOfExternalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_roscpp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rosgraph_msgs': ['/opt/ros/indigo/share/rosgraph_msgs/cmake/../msg'], 'test_roscpp': ['/home/cracker/workspace/src/ros_comm/test/test_roscpp/test/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/test_serialization/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/perf/msg', '/home/cracker/workspace/src/ros_comm/test/test_roscpp/perf_serialization/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cc431047757f431ecd2754e03aa592f8";
  }

  static const char* value(const ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcc431047757f431eULL;
  static const uint64_t static_value2 = 0xcd2754e03aa592f8ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_roscpp/VariableLengthArrayOfExternal";
  }

  static const char* value(const ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This comment has \"quotes\" in it\n\
rosgraph_msgs/Log[] a\n\
================================================================================\n\
MSG: rosgraph_msgs/Log\n\
##\n\
## Severity level constants\n\
##\n\
byte DEBUG=1 #debug level\n\
byte INFO=2  #general level\n\
byte WARN=4  #warning level\n\
byte ERROR=8 #error level\n\
byte FATAL=16 #fatal/critical level\n\
##\n\
## Fields\n\
##\n\
Header header\n\
byte level\n\
string name # name of the node\n\
string msg # message \n\
string file # file the message came from\n\
string function # function the message came from\n\
uint32 line # line the message came from\n\
string[] topics # topic names that the node publishes\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct VariableLengthArrayOfExternal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_roscpp::VariableLengthArrayOfExternal_<ContainerAllocator>& v)
  {
    s << indent << "a[]" << std::endl;
    for (size_t i = 0; i < v.a.size(); ++i)
    {
      s << indent << "  a[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosgraph_msgs::Log_<ContainerAllocator> >::stream(s, indent + "    ", v.a[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ROSCPP_MESSAGE_VARIABLELENGTHARRAYOFEXTERNAL_H
