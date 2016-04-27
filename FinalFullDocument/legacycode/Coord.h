#ifndef _COORD_H_
#define _COORD_H_

#include <string>

class Coord
{
public:
	Coord();
	~Coord();
    

    
	int getX();
	void setX(int val);

	int getY();
	void setY(int val);
	
	bool isTracking();
	void setTracking(bool val);
	std::string printTracking();

private:
    bool tracking;
	int  xPos, yPos;

};

#endif
