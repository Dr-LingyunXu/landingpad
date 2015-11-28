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
		setHSVmin(cv::Scalar(34, 161, 57));
		setHSVmax(cv::Scalar(50, 255, 90));

		//BGR value for Green:
		setText(cv::Scalar(0,255,0));
	}
	if(name=="yellow")
	{
		setHSVmin(cv::Scalar(8, 174, 169));
		setHSVmax(cv::Scalar(32, 255, 255));

		//BGR value for Yellow:
		setText(cv::Scalar(0,255,255));
	}
	if(name=="red")
	{
        setHSVmin(cv::Scalar(0,200,117));
        setHSVmax(cv::Scalar(6,255,200));

		//BGR value for Red:
		setText(cv::Scalar(0,0,255));
	}
	if(name=="blue")
	{
		setHSVmin(cv::Scalar(105, 30, 58));
		setHSVmax(cv::Scalar(142, 117, 98));

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


