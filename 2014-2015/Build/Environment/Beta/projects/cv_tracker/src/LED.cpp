/*************************************************************************//**
 * @file LED.cpp
 *
 * @author Julian Brackins
 *
 * @brief SOURCE - class for LED groupings. HSV values stored in this class.
 *
 *****************************************************************************/
 
#include "../inc/LED.h"

/**************************************************************************//**
 * @author Julian Brackins
 *
 * @par Description:
 * LED Constructor. The empty constructor should never be used...
 *
 *****************************************************************************/
LED::LED()
{

}

/**************************************************************************//**
 * @author Julian Brackins
 *
 * @par Description:
 * LED Constructor for when a name is passed in as a parameter. This decides
 * what colour the LED is.
 *
 *****************************************************************************/
LED::LED(std::string name)
{

	setColour(name);

    //TODO: Adjust HSV vals to something more appropriate...	
	if(name=="green")
	{
		setHSVmin(cv::Scalar(57, 116, 132));
		setHSVmax(cv::Scalar(69, 154, 177));

		//BGR value for Green:
		setText(cv::Scalar(0,255,0));
	}
	if(name=="yellow")
	{
		setHSVmin(cv::Scalar(17, 34, 201));
		setHSVmax(cv::Scalar(45, 256, 256));

		//BGR value for Yellow:
		setText(cv::Scalar(0,255,255));
	}
	if(name=="red")
	{
        setHSVmin(cv::Scalar(0,205,121));
        setHSVmax(cv::Scalar(8,256,224));

		//BGR value for Red:
		setText(cv::Scalar(0,0,255));
	}
	if(name=="blue")
	{
		setHSVmin(cv::Scalar(100, 140, 105));
		setHSVmax(cv::Scalar(120, 180, 181));

		//BGR value for Red:
		setText(cv::Scalar(0,0,255));
	}
	if(name=="calibrate")
	{
		setHSVmin(cv::Scalar(0, 0, 0));
		setHSVmax(cv::Scalar(256, 256, 256));

		//BGR value for Red:
		setText(cv::Scalar(0,0,255));	
	}

}

/**************************************************************************//**
 * @author Julian Brackins
 *
 * @par Description:
 * LED Destructor.
 *
 *****************************************************************************/
LED::~LED()
{

}


