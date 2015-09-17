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
 * Auto-generated by gensrv_cpp from file /home/cracker/workspace/src/ethzasl_ptam/ptam_com/srv/KeyFrame_srv.srv
 *
 */


#ifndef PTAM_COM_MESSAGE_KEYFRAME_SRV_H
#define PTAM_COM_MESSAGE_KEYFRAME_SRV_H

#include <ros/service_traits.h>


#include <ptam_com/KeyFrame_srvRequest.h>
#include <ptam_com/KeyFrame_srvResponse.h>


namespace ptam_com
{

struct KeyFrame_srv
{

typedef KeyFrame_srvRequest Request;
typedef KeyFrame_srvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct KeyFrame_srv
} // namespace ptam_com


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ptam_com::KeyFrame_srv > {
  static const char* value()
  {
    return "1950b962db053cd38d36594521dda474";
  }

  static const char* value(const ::ptam_com::KeyFrame_srv&) { return value(); }
};

template<>
struct DataType< ::ptam_com::KeyFrame_srv > {
  static const char* value()
  {
    return "ptam_com/KeyFrame_srv";
  }

  static const char* value(const ::ptam_com::KeyFrame_srv&) { return value(); }
};


// service_traits::MD5Sum< ::ptam_com::KeyFrame_srvRequest> should match 
// service_traits::MD5Sum< ::ptam_com::KeyFrame_srv > 
template<>
struct MD5Sum< ::ptam_com::KeyFrame_srvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ptam_com::KeyFrame_srv >::value();
  }
  static const char* value(const ::ptam_com::KeyFrame_srvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ptam_com::KeyFrame_srvRequest> should match 
// service_traits::DataType< ::ptam_com::KeyFrame_srv > 
template<>
struct DataType< ::ptam_com::KeyFrame_srvRequest>
{
  static const char* value()
  {
    return DataType< ::ptam_com::KeyFrame_srv >::value();
  }
  static const char* value(const ::ptam_com::KeyFrame_srvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ptam_com::KeyFrame_srvResponse> should match 
// service_traits::MD5Sum< ::ptam_com::KeyFrame_srv > 
template<>
struct MD5Sum< ::ptam_com::KeyFrame_srvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ptam_com::KeyFrame_srv >::value();
  }
  static const char* value(const ::ptam_com::KeyFrame_srvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ptam_com::KeyFrame_srvResponse> should match 
// service_traits::DataType< ::ptam_com::KeyFrame_srv > 
template<>
struct DataType< ::ptam_com::KeyFrame_srvResponse>
{
  static const char* value()
  {
    return DataType< ::ptam_com::KeyFrame_srv >::value();
  }
  static const char* value(const ::ptam_com::KeyFrame_srvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PTAM_COM_MESSAGE_KEYFRAME_SRV_H
