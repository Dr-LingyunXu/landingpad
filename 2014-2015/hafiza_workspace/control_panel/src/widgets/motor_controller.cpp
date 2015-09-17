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
 * \file   gps_display.cpp
 * \date   Jan 20, 2012
 * \author Matt Richard
 */
#include <QtGui>
#include "control_panel/widgets/motor_controller.h"
#include "control_panel/globals.h"

Controller::ControllerDisplay(QWidget *parent) : QWidget(parent)
{
	controller_name = "Controller";

	// Assume use of all labels
	use_steering = true;
	use_velocity = true;
	use_landing_fwd = true;
	use_landing_lft = true;

	createWidget();
}

ControllerDisplay::ControllerDisplay(const QString &name, bool show_steering, bool show_velocity,
	bool show_landing_fwd, bool show_landing_lft, QWidget *parent) : QWidget(parent)
{
	if(name.isEmpty())
		controller_name = "Controller";
	else
		controller_name = name;

	use_steering = show_steering;
	use_velocity = show_velocity;
	use_landing_fwd = show_landing_fwd;
	use_landing_lft = show_landing_lft;

	createWidget();
}

void ControllerDisplay::createWidget()
{
	// counter for the grid layout
	int rows = 0;

	// initialize priavte variables
	zeroValues();

	widget_layout = new QHBoxLayout;

	// Grid layout for labels
	QGridLayout *controller_gridlayout = new QGridLayout;

	// Only display the GPS name if any attributes will be displayed
	if(use_steering || use_velocity || use_landing_fwd || use_landing_lft)
	{
		name_label = new QLabel(controller_name);

		gps_gridlayout->addWidget(name_label, rows, 0, 1, 0);
		rows++;

		controller_gridlayout->setColumnMinimumWidth(1, 8);
	}

	// Create latitude label and add to layout
	if(use_steering)
	{
		steering_label = new QLabel;

		steering_gridlayout->addWidget(new QLabel(tr("S: ")), rows, 0, Qt::AlignLeft);
		steering_gridlayout->addWidget(steering_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create longitude label and add to layout
	if(use_velocity)
	{
		velocity_label = new QLabel;

		controller_gridlayout->addWidget(new QLabel(tr("V: ")), rows, 0, Qt::AlignLeft);
		controller_gridlayout->addWidget(velocity_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create altitude label and add to layout
	if(use_landing_fwd)
	{
		landing_fwd_label = new QLabel;

		controller_gridlayout->addWidget(new QLabel(tr("LF: ")), rows, 0, Qt::AlignLeft);
		controller_gridlayout->addWidget(landing_fwd_label, rows, 1, Qt::AlignLeft);
		rows++;
	}

	if(use_landing_lft)
        {
                landing_lft_label = new QLabel;

                controller_gridlayout->addWidget(new QLabel(tr("LF: ")), rows, 0, Qt::AlignLeft);
                controller_gridlayout->addWidget(landing_lft_label, rows, 1, Qt::AlignLeft);
                rows++;
        }


	widget_layout->addLayout(controller_gridlayout);
	setLayout(widget_layout);
}

void ControllerDisplay::zeroValues()
{
	// Zero private variables
	steering = " ";
	velocity = " ";
	landing_fwd = " ";
	landing_lft = " ";
}

void ControllerDisplay::updateControllerDisplay(QString data)
{

	/*
	int i;
	QStringList values = data.split(",", QString::SkipEmptyParts);
	steering = values[0];
	velocity = values[1];
	landing_fwd = values[2];
	landing_lft = values[3];
	*/

	steering = "w";
	velocity = "x";
	landing_fwd = "y";
	landing_lft = "z";

	steering_label->setText(steering);
	velocity_label->setText(velocity);
	landing_fwd_label->setText(landing_fwd);
	landing_lft_label->setText(landing_lft);
}
