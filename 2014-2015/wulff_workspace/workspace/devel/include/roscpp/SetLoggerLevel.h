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
 * Auto-generated by gensrv_cpp from file /home/cracker/workspace/src/ros_comm/clients/roscpp/srv/SetLoggerLevel.srv
 *
 */


#ifndef ROSCPP_MESSAGE_SETLOGGERLEVEL_H
#define ROSCPP_MESSAGE_SETLOGGERLEVEL_H

#include <ros/service_traits.h>


#include <roscpp/SetLoggerLevelRequest.h>
#include <roscpp/SetLoggerLevelResponse.h>


namespace roscpp
{

struct SetLoggerLevel
{

typedef SetLoggerLevelRequest Request;
typedef SetLoggerLevelResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetLoggerLevel
} // namespace roscpp


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::roscpp::SetLoggerLevel > {
  static const char* value()
  {
    return "51da076440d78ca1684d36c868df61ea";
  }

  static const char* value(const ::roscpp::SetLoggerLevel&) { return value(); }
};

template<>
struct DataType< ::roscpp::SetLoggerLevel > {
  static const char* value()
  {
    return "roscpp/SetLoggerLevel";
  }

  static const char* value(const ::roscpp::SetLoggerLevel&) { return value(); }
};


// service_traits::MD5Sum< ::roscpp::SetLoggerLevelRequest> should match 
// service_traits::MD5Sum< ::roscpp::SetLoggerLevel > 
template<>
struct MD5Sum< ::roscpp::SetLoggerLevelRequest>
{
  static const char* value()
  {
    return MD5Sum< ::roscpp::SetLoggerLevel >::value();
  }
  static const char* value(const ::roscpp::SetLoggerLevelRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::roscpp::SetLoggerLevelRequest> should match 
// service_traits::DataType< ::roscpp::SetLoggerLevel > 
template<>
struct DataType< ::roscpp::SetLoggerLevelRequest>
{
  static const char* value()
  {
    return DataType< ::roscpp::SetLoggerLevel >::value();
  }
  static const char* value(const ::roscpp::SetLoggerLevelRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::roscpp::SetLoggerLevelResponse> should match 
// service_traits::MD5Sum< ::roscpp::SetLoggerLevel > 
template<>
struct MD5Sum< ::roscpp::SetLoggerLevelResponse>
{
  static const char* value()
  {
    return MD5Sum< ::roscpp::SetLoggerLevel >::value();
  }
  static const char* value(const ::roscpp::SetLoggerLevelResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::roscpp::SetLoggerLevelResponse> should match 
// service_traits::DataType< ::roscpp::SetLoggerLevel > 
template<>
struct DataType< ::roscpp::SetLoggerLevelResponse>
{
  static const char* value()
  {
    return DataType< ::roscpp::SetLoggerLevel >::value();
  }
  static const char* value(const ::roscpp::SetLoggerLevelResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROSCPP_MESSAGE_SETLOGGERLEVEL_H
