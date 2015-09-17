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
 * Auto-generated by gensrv_cpp from file /home/cracker/workspace/src/ros_comm/test/test_rospy/srv/StringString.srv
 *
 */


#ifndef TEST_ROSPY_MESSAGE_STRINGSTRING_H
#define TEST_ROSPY_MESSAGE_STRINGSTRING_H

#include <ros/service_traits.h>


#include <test_rospy/StringStringRequest.h>
#include <test_rospy/StringStringResponse.h>


namespace test_rospy
{

struct StringString
{

typedef StringStringRequest Request;
typedef StringStringResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StringString
} // namespace test_rospy


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::test_rospy::StringString > {
  static const char* value()
  {
    return "37bf11bf0378473e105b4a52f61d1a75";
  }

  static const char* value(const ::test_rospy::StringString&) { return value(); }
};

template<>
struct DataType< ::test_rospy::StringString > {
  static const char* value()
  {
    return "test_rospy/StringString";
  }

  static const char* value(const ::test_rospy::StringString&) { return value(); }
};


// service_traits::MD5Sum< ::test_rospy::StringStringRequest> should match 
// service_traits::MD5Sum< ::test_rospy::StringString > 
template<>
struct MD5Sum< ::test_rospy::StringStringRequest>
{
  static const char* value()
  {
    return MD5Sum< ::test_rospy::StringString >::value();
  }
  static const char* value(const ::test_rospy::StringStringRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::test_rospy::StringStringRequest> should match 
// service_traits::DataType< ::test_rospy::StringString > 
template<>
struct DataType< ::test_rospy::StringStringRequest>
{
  static const char* value()
  {
    return DataType< ::test_rospy::StringString >::value();
  }
  static const char* value(const ::test_rospy::StringStringRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::test_rospy::StringStringResponse> should match 
// service_traits::MD5Sum< ::test_rospy::StringString > 
template<>
struct MD5Sum< ::test_rospy::StringStringResponse>
{
  static const char* value()
  {
    return MD5Sum< ::test_rospy::StringString >::value();
  }
  static const char* value(const ::test_rospy::StringStringResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::test_rospy::StringStringResponse> should match 
// service_traits::DataType< ::test_rospy::StringString > 
template<>
struct DataType< ::test_rospy::StringStringResponse>
{
  static const char* value()
  {
    return DataType< ::test_rospy::StringString >::value();
  }
  static const char* value(const ::test_rospy::StringStringResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TEST_ROSPY_MESSAGE_STRINGSTRING_H
