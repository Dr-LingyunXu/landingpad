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
 * \file   gps_display.h
 * \date   Jan 20, 2012
 * \author Matt Richard
 */
#ifndef CONTROL_PANEL_CONTROLLER_DISPLAY_H
#define CONTROL_PANEL_CONTROLLER_DISPLAY_H

#include <QWidget>
#include <QString>

QT_BEGIN_NAMESPACE
class QHBoxLayout;
class QLabel;
QT_END_NAMESPACE

/**
 * \class GpsDisplay
 * \brief Widget for displaying latitude, logitude, and altitude from a robot's GPS device.
 */
class ControllerDisplay : public QWidget
{
	Q_OBJECT

	public:
		static void doNothing() { }
		/**
		 * \brief Constructor. Assumes use of all GPS attributes (latitude, logitude, and altitude).
		 *
		 * \param parent The parent widget.
		 */
		ControllerDisplay(QWidget *parent = 0);

		/**
		 * \brief Constructor. Allows for indication of what GPS attributes to display.
		 *
		 * \param name      The GPS device name to be displayed.
		 * \param show_lat  Indicates whether the latitude label should be displayed.
		 * \param show_long Indicates whether the longitude label should be displayed.
		 * \param show_alt  Indicates whether the altitude label should be displayed.
		 * \param parent    The parent widget.
		 */
		ControllerDisplay(const QString &name, bool show_steer_left = true,
			   bool show_velocity = true, bool show_landing_fwd = true, 
			   bool show_landing_left = true, QWidget *parent = 0);

		/**
		 * \brief Returns the current value of steering.
		 * \positive -> right, negative -> left
		 */
		QString getSteering() const { return steering; }

		/**
		 * \brief Returns the current value of velocity in rpm.
		 * \positive -> going forward, negative -> reverse
		 */
		QString getVelocity() const { return velocity; }

		/**
		 * \brief Returns the current value of LF in rad.
		 */
		QString getLandingFwd() const { return landing_fwd; }

		/**
                 * \brief Returns the current value of LL in rad.
                 */
                QString getLandingLft() const { return landing_lft; }


		/**
		 * \brief Zeros latitude, logitude, and altitude values.
		 */
		void zeroValues();

	public slots:
		/**
		 * \brief SLOT that will update the latitude, longitude, and altitude labels.
		 *
		 * \param lat New latitude value.
		 * \param lon New longitude value.
		 * \param alt New altitude value, if used.
		 */
		void updateControllerDisplay(QString data);

	private:
		/**
		 * \brief Dynamically layouts the widget according to the flags set when the widget was created.
		 */
		void createWidget();

		QHBoxLayout *widget_layout;

		QString controller_name;

		// Flags indicating what attributes the robot's GPS device has
		bool use_steering;
		bool use_velocity;
		bool use_landing_fwd;
		bool use_landing_lft;

		QString steering;
		QString velocity;
		QString landing_fwd;
		QString landing_lft;

		QLabel *name_label;
		QLabel *steering_label;
		QLabel *velocity_label;
		QLabel *landing_fwd_label;
		QLabel *landing_lft_label;
};

#endif // CONTROL_PANEL_GPS_DISPLAY_H
