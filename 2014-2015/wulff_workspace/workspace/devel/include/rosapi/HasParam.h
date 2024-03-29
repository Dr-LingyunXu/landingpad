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
 * Auto-generated by gensrv_cpp from file /home/cracker/workspace/src/rosbridge_suite/rosapi/srv/HasParam.srv
 *
 */


#ifndef ROSAPI_MESSAGE_HASPARAM_H
#define ROSAPI_MESSAGE_HASPARAM_H

#include <ros/service_traits.h>


#include <rosapi/HasParamRequest.h>
#include <rosapi/HasParamResponse.h>


namespace rosapi
{

struct HasParam
{

typedef HasParamRequest Request;
typedef HasParamResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct HasParam
} // namespace rosapi


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rosapi::HasParam > {
  static const char* value()
  {
    return "ed3df286bd6dff9b961770f577454ea9";
  }

  static const char* value(const ::rosapi::HasParam&) { return value(); }
};

template<>
struct DataType< ::rosapi::HasParam > {
  static const char* value()
  {
    return "rosapi/HasParam";
  }

  static const char* value(const ::rosapi::HasParam&) { return value(); }
};


// service_traits::MD5Sum< ::rosapi::HasParamRequest> should match 
// service_traits::MD5Sum< ::rosapi::HasParam > 
template<>
struct MD5Sum< ::rosapi::HasParamRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rosapi::HasParam >::value();
  }
  static const char* value(const ::rosapi::HasParamRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosapi::HasParamRequest> should match 
// service_traits::DataType< ::rosapi::HasParam > 
template<>
struct DataType< ::rosapi::HasParamRequest>
{
  static const char* value()
  {
    return DataType< ::rosapi::HasParam >::value();
  }
  static const char* value(const ::rosapi::HasParamRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rosapi::HasParamResponse> should match 
// service_traits::MD5Sum< ::rosapi::HasParam > 
template<>
struct MD5Sum< ::rosapi::HasParamResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rosapi::HasParam >::value();
  }
  static const char* value(const ::rosapi::HasParamResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rosapi::HasParamResponse> should match 
// service_traits::DataType< ::rosapi::HasParam > 
template<>
struct DataType< ::rosapi::HasParamResponse>
{
  static const char* value()
  {
    return DataType< ::rosapi::HasParam >::value();
  }
  static const char* value(const ::rosapi::HasParamResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROSAPI_MESSAGE_HASPARAM_H
