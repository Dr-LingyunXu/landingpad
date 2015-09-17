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
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/ros_comm/test/test_rosmaster/msg/Floats.msg
 *
 */


#ifndef TEST_ROSMASTER_MESSAGE_FLOATS_H
#define TEST_ROSMASTER_MESSAGE_FLOATS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test_rosmaster
{
template <class ContainerAllocator>
struct Floats_
{
  typedef Floats_<ContainerAllocator> Type;

  Floats_()
    : float32(0.0)
    , float64(0.0)  {
    }
  Floats_(const ContainerAllocator& _alloc)
    : float32(0.0)
    , float64(0.0)  {
    }



   typedef float _float32_type;
  _float32_type float32;

   typedef double _float64_type;
  _float64_type float64;




  typedef boost::shared_ptr< ::test_rosmaster::Floats_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_rosmaster::Floats_<ContainerAllocator> const> ConstPtr;

}; // struct Floats_

typedef ::test_rosmaster::Floats_<std::allocator<void> > Floats;

typedef boost::shared_ptr< ::test_rosmaster::Floats > FloatsPtr;
typedef boost::shared_ptr< ::test_rosmaster::Floats const> FloatsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_rosmaster::Floats_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_rosmaster::Floats_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test_rosmaster

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'test_rosmaster': ['/home/cracker/workspace/src/ros_comm/test/test_rosmaster/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test_rosmaster::Floats_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_rosmaster::Floats_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_rosmaster::Floats_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_rosmaster::Floats_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_rosmaster::Floats_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_rosmaster::Floats_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_rosmaster::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1ee8aba2d870f75f2b5916e2cddbd928";
  }

  static const char* value(const ::test_rosmaster::Floats_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1ee8aba2d870f75fULL;
  static const uint64_t static_value2 = 0x2b5916e2cddbd928ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_rosmaster::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_rosmaster/Floats";
  }

  static const char* value(const ::test_rosmaster::Floats_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_rosmaster::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# for rostopic tests\n\
float32 float32\n\
float64 float64\n\
";
  }

  static const char* value(const ::test_rosmaster::Floats_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_rosmaster::Floats_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.float32);
      stream.next(m.float64);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Floats_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_rosmaster::Floats_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_rosmaster::Floats_<ContainerAllocator>& v)
  {
    s << indent << "float32: ";
    Printer<float>::stream(s, indent + "  ", v.float32);
    s << indent << "float64: ";
    Printer<double>::stream(s, indent + "  ", v.float64);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_ROSMASTER_MESSAGE_FLOATS_H
