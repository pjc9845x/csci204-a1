/*
File: Point2D.h

Point2D class:

*/
#ifndef Point2D_h
#define Point2D_h

#include "LocationData.h"
#include <iostream>
#include <string>
using namespace std;

class Point2D
{
    private:
        int x;
        int y;
        float civIndex;

    public:
        LocationData lData;
        Point2D();
        Point2D(int, int, LocationData, float);

        //=====METHODS=======
        //Mutators
        void setX();
        void setY();
        void setLocationData();
        void setCivIndex();

        //Assessors
        int getX();
        int getY();
        LocationData getLocationData();
        float getCivIndex();

        //Other Methods
        string toString(int , int, LocationData , float);
};

Point2D::Point2D()
{

}

Point2D::Point2D(int x, int y, LocationData lData, float civIndex)
{
    this->x=x;
    this->y=y;
    this->lData=lData;
    this->civIndex=civIndex;
}
//=====METHODS=======
//Mutators
void Point2D::setX()
{
    this->x=x;
}
void Point2D::setY()
{
    this->y=y;
}
void Point2D::setLocationData()
{
    this->lData=lData;
}
void Point2D::setCivIndex()
{
    this->civIndex=civIndex;
}

//Assessors
int Point2D::getX()
{
    return x;
}

int Point2D::getY()
{
    return y;
}

LocationData Point2D::getLocationData()
{
    return lData;
}

float Point2D::getCivIndex()
{
    return civIndex;
}

//Other Methods
string Point2D::toString(int x, int y, LocationData lData, float civIndex)
{

}

#endif
