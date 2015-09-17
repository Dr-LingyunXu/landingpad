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
#include "control_panel/widgets/artag_display.h"
#include "control_panel/globals.h"

ArtagDisplay::ArtagDisplay(QWidget *parent) : QWidget(parent)
{
	artag_name = "AR Tag Postion";
	orientation = "AT Tag Orientation";
	// Assume use of all labels
	use_x = true;
	use_y = true;
	use_z = true;


	createWidget();
}

ArtagDisplay::ArtagDisplay(const QString &name, bool show_x, bool show_y,
	bool show_z, QWidget *parent) : QWidget(parent)
{
	if(name.isEmpty())
	{
		artag_name = "AR Tag Position";
		orientation = "AR Tag Orientation";
	}
	else
	{
		artag_name = name;
		orientation = "Orientation";
	}
	use_x = show_x;
	use_y = show_y;
	use_z = show_z;

	createWidget();
}

void ArtagDisplay::createWidget()
{
	// counter for the grid layout
	int rows = 0;

	// initialize priavte variables
	zeroValues();

	widget_layout = new QHBoxLayout;

	// Grid layout for labels
	QGridLayout *artag_gridlayout = new QGridLayout;

	// Only display the GPS name if any attributes will be displayed
	if(use_x || use_y || use_z)
	{
		name_label = new QLabel(artag_name);

		artag_gridlayout->addWidget(name_label, rows, 0, 1, 0);
		rows++;

		artag_gridlayout->setColumnMinimumWidth(1, 8);
	}

	// Create latitude label and add to layout
	if(use_x)
	{
		x_label = new QLabel;

		artag_gridlayout->addWidget(new QLabel(tr("x: ")), rows, 0, Qt::AlignLeft);
		artag_gridlayout->addWidget(x_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create longitude label and add to layout
	if(use_y)
	{
		y_label = new QLabel;

		artag_gridlayout->addWidget(new QLabel(tr("y: ")), rows, 0, Qt::AlignLeft);
		artag_gridlayout->addWidget(y_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create altitude label and add to layout
	if(use_z)
	{
		z_label = new QLabel;

		artag_gridlayout->addWidget(new QLabel(tr("z: ")), rows, 0, Qt::AlignLeft);
		artag_gridlayout->addWidget(z_label, rows, 1, Qt::AlignLeft);
		rows++;
	}

	orient_label = new QLabel(orientation);
	artag_gridlayout->addWidget(name_label, rows, 0, 1, 0);
        rows++;

        artag_gridlayout->setColumnMinimumWidth(1, 8);

	roll_label = new QLabel;
	artag_gridlayout->addWidget(new QLabel(tr("Roll: ")), rows, 0, Qt::AlignLeft);
        artag_gridlayout->addWidget(roll_label, rows, 1, Qt::AlignRight);
        rows++;

	pitch_label = new QLabel;
        artag_gridlayout->addWidget(new QLabel(tr("Pitch: ")), rows, 0, Qt::AlignLeft);
        artag_gridlayout->addWidget(pitch_label, rows, 1, Qt::AlignRight);
        rows++;

 	yaw_label = new QLabel;
        artag_gridlayout->addWidget(new QLabel(tr("Yaw: ")), rows, 0, Qt::AlignLeft);
        artag_gridlayout->addWidget(yaw_label, rows, 1, Qt::AlignRight);
        rows++;

	widget_layout->addLayout(artag_gridlayout);
	setLayout(widget_layout);
}

void ArtagDisplay::zeroValues()
{
	// Zero private variables
	x = 0.0;
	y = 0.0;
	z = 0.0;
	roll = 0.0;
	pitch = 0.0;
	yaw = 0.0;
}

void ArtagDisplay::updateArtagDisplay(QString data)
{
	/*int i;

        QStringList coordinates = data.split(")", QString::SkipEmptyParts);
        for(i = 0; i < coordinates.size(); i++)
                coordinates[i].append(")");

        coordinates[1].remove(0, 1);
        coordinates[3].remove(0, 1);
        coordinates[5].remove(0, 1);

        x = coordinates[1];
        y = coordinates[3];
        z = coordinates[5];*/


        x_label->setText(x);
        y_label->setText(y);
        z_label->setText(z);
	roll_label->setText(roll);
	pitch_label->setText(pitch);
	yaw_label->setText(yaw);
}
