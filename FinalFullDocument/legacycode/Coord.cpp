#include "Coord.h"


Coord::Coord()
{
    setX(0);
    setY(0);
    setTracking(false);
}


Coord::~Coord()
{
}


int Coord::getX()
{
	return Coord::xPos;
}

void Coord::setX(int val)
{
	Coord::xPos = val;
}

int Coord::getY()
{
	return Coord::yPos;
}

void Coord::setY(int val)
{
	Coord::yPos = val;
}


bool Coord::isTracking()
{
    return Coord::tracking;
}

std::string Coord::printTracking()
{
    if(Coord::tracking)
        return "true";
    else
        return "false";
}

void Coord::setTracking(bool val)
{
    Coord::tracking = val;
}
