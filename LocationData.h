/*
File: LocationData.h

LocationData class
*/
#ifndef LocationData_h
#define LocationData_h

#include <string>
using namespace std;

class LocationData
{
    private:
        string sunType;
        int noOfEarthLikePlanets;
        int noOfEarthLikeMoons;
        float aveParticulateDensity;
        float avePlasmaDensity;

    public:
        LocationData();
        LocationData(string, int , int, float , float);
        string toString();

        //=====METHODS=======
        //Mutators
        void setSunType();
        void setEarthLikePlanets();
        void setEarthLikeMoons();
        void setAveParticulateDensity();
        void setAvePlasmaDensity();

        //Assessors
        string getSunType();
        int getEarthLikePlanets();
        int getEarthLikeMoons();
        float getAveParticulateDensity();
        float getAvePlasmaDensity();

        //Other Methods
        static float computeCivIndex (string, int , int, float , float);
        string toString(string, int , int, float , float);

};

LocationData::LocationData()
{}

LocationData::LocationData(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons,
                     float aveParticulateDensity, float avePlasmaDensity)
{
    this->sunType=sunType;
    this->noOfEarthLikePlanets=noOfEarthLikePlanets;
    this->noOfEarthLikeMoons=noOfEarthLikeMoons;
    this->aveParticulateDensity=aveParticulateDensity;
    this->avePlasmaDensity=avePlasmaDensity;
}

//Mutators
void LocationData::setSunType()
{
    this->sunType=sunType;
}

void LocationData::setEarthLikePlanets()
{
    this->noOfEarthLikePlanets=noOfEarthLikePlanets;
}

void LocationData::setEarthLikeMoons()
{
    this->noOfEarthLikeMoons=noOfEarthLikeMoons;
}

void LocationData::setAveParticulateDensity()
{
    this->aveParticulateDensity=aveParticulateDensity;
}

void LocationData::setAvePlasmaDensity()
{
    this->avePlasmaDensity=avePlasmaDensity;
}


//Assessors
string LocationData::getSunType()
{
    return sunType;
}

int LocationData::getEarthLikePlanets()
{
    return noOfEarthLikePlanets;
}

int LocationData::getEarthLikeMoons()
{
    return noOfEarthLikeMoons;
}

float LocationData::getAveParticulateDensity()
{
    return aveParticulateDensity;
}

float LocationData::getAvePlasmaDensity()
{
    return avePlasmaDensity;
}

//Other Methods
float LocationData::computeCivIndex (string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons,
                     float aveParticulateDensity, float avePlasmaDensity)
{
    float sunTypePercent;

    if(!sunType.compare("Type O"))
        sunTypePercent=30;
    else if(!sunType.compare("Type B"))
        sunTypePercent=45;
    else if(!sunType.compare("Type A"))
        sunTypePercent=60;
    else if(!sunType.compare("Type F"))
        sunTypePercent=75;
    else if(!sunType.compare("Type G"))
        sunTypePercent=90;
    else if(!sunType.compare("Type K"))
        sunTypePercent=80;
    else if(!sunType.compare("Type M"))
        sunTypePercent=70;

    float civIndex=((sunTypePercent/100)-(aveParticulateDensity+avePlasmaDensity)/200)*(noOfEarthLikePlanets+noOfEarthLikeMoons);
    return civIndex;
}

string LocationData::toString(string sunType, int noOfEarthLikePlanets, int noOfEarthLikeMoons,
                     float aveParticulateDensity, float avePlasmaDensity)
{


}

#endif
