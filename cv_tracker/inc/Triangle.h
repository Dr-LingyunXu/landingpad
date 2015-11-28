#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <string>
#include <iostream>
#include "Coord.h"
#include "math.h"
#define PI 3.14159265

class Triangle
{
public:
	Triangle();
	Triangle(Coord c1, Coord c2, Coord c3);
	~Triangle();
    

	void setPoint(std::string pointName, Coord point);
	void setSide(std::string sideName, Coord firstPoint, Coord secondPoint);
	double calcSide(Coord P1, Coord P2);
	Coord getPoint(std::string pointName);
	double getSide(std::string sideName);
	
	//find all angles
    void lawOfCosines();
    double radToDeg(double radVal);
    
    void printTriangle();
    
private:

    //Reminder:
    //sideA = dist(pointB, pointC);
    //sideB = dist(pointA, pointC);
    //sideC = dist(pointA, pointB);
    
    //Angle A = angle at pointA,
    //Angle B = angle at pointB,
    //Angle C = angle at pointC,
    double sideA, sideB, sideC;
	Coord pointA, pointB, pointC;
    double angleA, angleB, angleC;
    
    
};

#endif
