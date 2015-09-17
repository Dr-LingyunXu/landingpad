/*************************************************************************//**
 * @file LED.h
 *
 * @author Julian Brackins
 *
 * @brief HEADER - class for LED groupings. HSV values stored in this class.
 *
 *****************************************************************************/
 
#ifndef _LED_H_
#define _LED_H_

/******************************************************************************
 *
 * INCLUDE
 *
 ******************************************************************************/
 
#include <string>
#include "opencv/cv.h"
#include "opencv/highgui.h"

/*************************************************************************//**
* @class LED
*
* @author Julian Brackins
*
* @brief LEDs! Not really anymore but who wants to mess with names.
*
*****************************************************************************/
class LED
{
public:
	LED();
    LED(std::string name);
	~LED();
	
	int getX()                  { return xPos; }
	void setX(int val)          { xPos = val; }

	int getY()                  { return LED::yPos; }
	void setY(int val)          { LED::yPos = val; }

    cv::Scalar getHSVmin()      { return LED::HSVmin; }
    cv::Scalar getHSVmax()      { return LED::HSVmax; }

    void setHSVmax(cv::Scalar val)  { LED::HSVmax = val; }
    void setHSVmin(cv::Scalar val)  { LED::HSVmin = val; }   
    
    std::string getColour()         { return colour; }
    void setColour(std::string val) { colour = val;  }
    
    cv::Scalar getText()         { return txtColour; }
    void setText(cv::Scalar val) { txtColour = val;  }

private:
	int xPos, yPos;
	std::string colour;
	cv::Scalar HSVmin, HSVmax;
	cv::Scalar txtColour;
};

#endif //LED_H
