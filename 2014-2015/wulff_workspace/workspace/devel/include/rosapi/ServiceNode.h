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
 * Auto-generated by gensrv_cpp from file /home/cracker/workspace/src/rosbridge_suite/rosapi/srv/ServiceNode.srv
 *
 */


#ifndef ROSAPI_MESSAGE_SERVICENODE_H
#define ROSAPI_MESSAGE_SERVICENODE_H

#include <ros/service_traits.h>


#include <rosapi/ServiceNodeRequest.h>
#include <rosapi/ServiceNodeResponse.h>


namespace rosapi
{

struct ServiceNode
{

typedef ServiceNodeRequest Request;
typedef ServiceNodeResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ServiceNode
} // namespace rosapi


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rosapi::ServiceNode > {
  static const char* value()
  {
    return "bd2a0a45fd7a73a86c8d6051d5a6db8a";
  }

  static const char* value(const ::rosapi::ServiceNode&) { return value(); }
};

template<>
struct DataType< ::rosapi::ServiceNode > {
  static const char* value()
  {
    return "rosapi/ServiceNode";
  }

  static const char* value(const ::rosapi::ServiceNode&) { return value(); }
};


// service_traits::MD5Sum< ::rosapi::ServiceNodeRequest> should match 
// service_traits::MD5Sum< ::rosapi::ServiceNode > 
template<>
struct MD5Sum< ::rosapi::ServiceNodeRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rosapi::ServiceNode >::value();
  }
  static const char* value(const ::rosapi::ServiceNodeRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosapi::ServiceNodeRequest> should match 
// service_traits::DataType< ::rosapi::ServiceNode > 
template<>
struct DataType< ::rosapi::ServiceNodeRequest>
{
  static const char* value()
  {
    return DataType< ::rosapi::ServiceNode >::value();
  }
  static const char* value(const ::rosapi::ServiceNodeRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rosapi::ServiceNodeResponse> should match 
// service_traits::MD5Sum< ::rosapi::ServiceNode > 
template<>
struct MD5Sum< ::rosapi::ServiceNodeResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rosapi::ServiceNode >::value();
  }
  static const char* value(const ::rosapi::ServiceNodeResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosapi::ServiceNodeResponse> should match 
// service_traits::DataType< ::rosapi::ServiceNode > 
template<>
struct DataType< ::rosapi::ServiceNodeResponse>
{
  static const char* value()
  {
    return DataType< ::rosapi::ServiceNode >::value();
  }
  static const char* value(const ::rosapi::ServiceNodeResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROSAPI_MESSAGE_SERVICENODE_H
