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
#include "control_panel/widgets/blob_display.h"
#include "control_panel/globals.h"

BlobDisplay::BlobDisplay(QWidget *parent) : QWidget(parent)
{
	blob_name = "Blob Detection";

	// Assume use of all labels
	use_red = true;
	use_green = true;
	use_blue = true;

	createWidget();
}

BlobDisplay::BlobDisplay(const QString &name, bool show_redBlob, bool show_greenBlob,
	bool show_blueBlob, QWidget *parent) : QWidget(parent)
{
	if(name.isEmpty())
		blob_name = "Blob Detection";
	else
		blob_name = name;

	use_red = show_redBlob;
	use_green = show_greenBlob;
	use_blue = show_greenBlob;

	createWidget();
}

void BlobDisplay::createWidget()
{
	// counter for the grid layout
	int rows = 0;

	// initialize private variables
	zeroValues();

	widget_layout = new QHBoxLayout;

	// Grid layout for labels
	QGridLayout *blob_gridlayout = new QGridLayout;

	// Only display the GPS name if any attributes will be displayed
	if(use_red || use_green || use_blue)
	{
		name_label = new QLabel(blob_name);

		blob_gridlayout->addWidget(name_label, rows, 0, 1, 0);
		rows++;

		blob_gridlayout->setColumnMinimumWidth(1, 8);
	}

	// Create red label and add to layout
	if(use_red)
	{
		red_label = new QLabel;

		blob_gridlayout->addWidget(new QLabel(tr("Red: ")), rows, 0, Qt::AlignLeft);
		blob_gridlayout->addWidget(red_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create green label and add to layout
	if(use_green)
	{
		green_label = new QLabel;

		blob_gridlayout->addWidget(new QLabel(tr("Green: ")), rows, 0, Qt::AlignLeft);
		blob_gridlayout->addWidget(green_label, rows, 1, Qt::AlignRight);
		rows++;
	}

	// Create blue label and add to layout
	if(use_blue)
	{
		blue_label = new QLabel;

		blob_gridlayout->addWidget(new QLabel(tr("Blue: ")), rows, 0, Qt::AlignLeft);
		blob_gridlayout->addWidget(blue_label, rows, 1, Qt::AlignLeft);
		rows++;
	}
	widget_layout->addStretch();
	widget_layout->addLayout(blob_gridlayout);
    	widget_layout->addStretch();

	setLayout(widget_layout);
}

void BlobDisplay::zeroValues()
{
	// Zero private variables
	redBlob = " ";
	greenBlob = " ";
	blueBlob = " ";
}

void BlobDisplay::updateBlobDisplay(QString data)
{

	//parse data topic 
	int i;
	QStringList coordinates = data.split(")", QString::SkipEmptyParts);
	for(i = 0; i < coordinates.size(); i++)
		coordinates[i].append(")");

	redBlob = coordinates[0];
	greenBlob = coordinates[1];
	blueBlob = coordinates[2];

	//display the info
	red_label->setText(redBlob);
	green_label->setText(greenBlob);
	blue_label->setText(blueBlob);
}
