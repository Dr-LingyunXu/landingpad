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
 * Auto-generated by genmsg_cpp from file /home/cracker/workspace/src/rosbridge_suite/rosapi/srv/ServiceResponseDetails.srv
 *
 */


#ifndef ROSAPI_MESSAGE_SERVICERESPONSEDETAILSRESPONSE_H
#define ROSAPI_MESSAGE_SERVICERESPONSEDETAILSRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <rosapi/TypeDef.h>

namespace rosapi
{
template <class ContainerAllocator>
struct ServiceResponseDetailsResponse_
{
  typedef ServiceResponseDetailsResponse_<ContainerAllocator> Type;

  ServiceResponseDetailsResponse_()
    : typedefs()  {
    }
  ServiceResponseDetailsResponse_(const ContainerAllocator& _alloc)
    : typedefs(_alloc)  {
    }



   typedef std::vector< ::rosapi::TypeDef_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::rosapi::TypeDef_<ContainerAllocator> >::other >  _typedefs_type;
  _typedefs_type typedefs;




  typedef boost::shared_ptr< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ServiceResponseDetailsResponse_

typedef ::rosapi::ServiceResponseDetailsResponse_<std::allocator<void> > ServiceResponseDetailsResponse;

typedef boost::shared_ptr< ::rosapi::ServiceResponseDetailsResponse > ServiceResponseDetailsResponsePtr;
typedef boost::shared_ptr< ::rosapi::ServiceResponseDetailsResponse const> ServiceResponseDetailsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rosapi

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'rosapi': ['/home/cracker/workspace/src/rosbridge_suite/rosapi/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d088db0da260a2cde072246a5f577519";
  }

  static const char* value(const ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd088db0da260a2cdULL;
  static const uint64_t static_value2 = 0xe072246a5f577519ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosapi/ServiceResponseDetailsResponse";
  }

  static const char* value(const ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "TypeDef[] typedefs\n\
\n\
================================================================================\n\
MSG: rosapi/TypeDef\n\
string type\n\
string[] fieldnames\n\
string[] fieldtypes\n\
int32[] fieldarraylen\n\
string[] examples\n\
";
  }

  static const char* value(const ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.typedefs);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ServiceResponseDetailsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosapi::ServiceResponseDetailsResponse_<ContainerAllocator>& v)
  {
    s << indent << "typedefs[]" << std::endl;
    for (size_t i = 0; i < v.typedefs.size(); ++i)
    {
      s << indent << "  typedefs[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::rosapi::TypeDef_<ContainerAllocator> >::stream(s, indent + "    ", v.typedefs[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSAPI_MESSAGE_SERVICERESPONSEDETAILSRESPONSE_H
