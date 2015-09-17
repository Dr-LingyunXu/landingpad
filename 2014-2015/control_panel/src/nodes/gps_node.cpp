/*
 * Copyright (c) 2011, 2012 Matt Richard, Scott K Logan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


/**
 * \file   gps_node.cpp
 * \date   Aug 31, 2011
 * \author Matt Richard
 * \brief  ROS node for received gps data.
 */
#include "control_panel/nodes/gps_node.h"

GpsNode::GpsNode(ros::NodeHandle *nh_ptr)
{
	topic_name = Globals::DEFAULT_GPS_TOPIC;

	nh = nh_ptr;
}

void GpsNode::subscribe()
{
	gps_sub = nh->subscribe(topic_name, 1, &GpsNode::gpsCallback, this,
		ros::TransportHints().unreliable().tcpNoDelay());
}

void GpsNode::unsubscribe()
{
	gps_sub.shutdown();
}

void GpsNode::gpsCallback(const sensor_msgs::NavSatFixConstPtr &msg)
{
	// Check for any NaN values
	if(msg->latitude != msg->latitude ||
	   msg->longitude != msg->longitude ||
	   msg->altitude != msg->altitude)
	{
		ROS_ERROR("NaN detected in NavSatFix message");
		return;
	}

	emit gpsDataReceived(msg->latitude, msg->longitude, msg->altitude);
}
