#include "Triangle.h"


Triangle::Triangle()
{
    sideA = 0.0;
    sideB = 0.0;
    sideC = 0.0;
}


Triangle::Triangle(Coord c1, Coord c2, Coord c3)
{
    pointA = c1;
    pointB = c2;
    pointC = c3;
}

Triangle::~Triangle()
{
}

void Triangle::setPoint(std::string pointName, Coord point)
{
    if(pointName == "A")
        pointA = point;
    else if(pointName == "B")
        pointB = point;
    else if(pointName == "C")
        pointC = point;
}

void Triangle::setSide(std::string sideName, Coord firstPoint, Coord secondPoint)
{
    double tempSide = 0.0;
    
    tempSide = calcSide(firstPoint, secondPoint);
    
    if(sideName == "A")
        sideA = tempSide;
    else if(sideName == "B")
        sideB = tempSide;
    else if(sideName == "C")
        sideC = tempSide;
}

double Triangle::calcSide(Coord P1, Coord P2)
{
    double xSquared = (P2.getX() - P1.getX()) * (P2.getX() - P1.getX());
    double ySquared = (P2.getY() - P1.getY()) * (P2.getY() - P1.getY());
    return sqrt( xSquared + ySquared );
}

Coord Triangle::getPoint(std::string pointName)
{
    if(pointName == "A")
        return pointA;
    else if(pointName == "B")
        return pointB;
    else if(pointName == "C")
        return pointC;

}

double Triangle::getSide(std::string sideName)
{
    if(sideName == "A")
        return sideA;
    else if(sideName == "B")
        return sideB;
    else if(sideName == "C")
        return sideC;
    else
        return -200.0;
}
	
void Triangle::lawOfCosines()
{
    //Calculate angleA
    angleA = ( (sideB*sideB) + (sideC*sideC) - (sideA*sideA) ) / (2 * sideB * sideC);
    angleA = acos(angleA);
    angleA = radToDeg(angleA);
    
    //Calculate angleB
    angleB = ( (sideC*sideC) + (sideA*sideA) - (sideB*sideB) ) / (2 * sideC * sideA);
    angleB = acos(angleB);
    angleB = radToDeg(angleB);
    
    angleC = 180.0 - angleA - angleB;
}

double Triangle::radToDeg(double radVal)
{
    return radVal * 180.0 / PI;
}

void Triangle::printTriangle()
{
    lawOfCosines();
    std::cout << "A: " << angleA << " degrees | ";
    std::cout << "B: " << angleB << " degrees | ";
    std::cout << "C: " << angleC << " degrees | ";
    std::cout << "Total: " << angleA+angleB+angleC << " degrees" << std::endl;
}
