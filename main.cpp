/*
File: MissionPlan.cpp

*/

#include <iostream>
#include <vector>
#include "LocationData.h"
#include "Point2D.h"
#include <cmath>
using namespace std;

void inputData();
void computeCIValue();
void printTop5();
void printDistance();

vector <Point2D> point2DVector;

int main()
{
    bool cont=true;

    while(cont)
    {
        int choice;

        cout<<"-----------------------------------"<<endl;
        cout<<"Mission Plan Program\n"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"Menu: \n"<<endl;
        cout<<"1 - Input statistical data"<<endl;
        cout<<"2 - Compute civ index value (for all records)"<<endl;
        cout<<"3 - Print top 5 exploration destinations"<<endl;
        cout<<"4 - Print total travel distance"<<endl;
        cout<<"5 - Exit"<<endl;
        cout<<endl;
        cout<<"Your choice: ";
        cin>>choice;

        cout<<"-----------------------------------"<<endl;
        switch (choice)
        {
            case 1: inputData();break;
            case 2: computeCIValue();break;
            case 3: printTop5();break;
            case 4: printDistance();break;
            case 5: cont=false;break;
            default: cout<<"Invalid input. Try again!"<<endl;
        }
    }
    cout<<"Goodbye!"<<endl;
}

void inputData()
{
    int x, y;
    char sunType;
    string s="Type ";
    int earthLikePlanets, earthLikeMoons;
    float partDensity, plasmaDensity;

    cout<<"Please enter x-ordinate: ";
    cin>>x;
    cout<<"Please enter y-ordinate: ";
    cin>>y;
    cout<<"Please enter sun type: ";
    bool cont=true;
    while(cont)
    {
        cin>>sunType;
        if(sunType!='O'&&sunType!='B'&&sunType!='A'&&sunType!='F'&&sunType!='G'&&sunType!='K'&&sunType!='M')
        {
            cout<<"Sorry, enter a valid sun type! Try again: ";
            cin>>sunType;
        }
        else
        {
            cont=false;
            break;
        }
    }
    cout<<"Please enter no. of earth-like planets: ";
    cin>>earthLikePlanets;
    cout<<"Please enter no. of earth-like moons: ";
    cin>>earthLikeMoons;
    cout<<"Please enter ave. particulate density: ";
    cin>>partDensity;
    cout<<"Please enter ave. plasma density: ";
    cin>>plasmaDensity;
    s.push_back(sunType);

    LocationData lData=LocationData(s,earthLikePlanets,earthLikeMoons,partDensity,plasmaDensity);
    Point2D p2D=Point2D(x,y,lData,0);
    point2DVector.push_back(p2D);

    cout<<endl;
    cout<<"Record successfully stored. Going back to main menu..."<<endl;
}

void computeCIValue()
{
    vector<Point2D>::iterator it;
    int k=0;

    for(it=point2DVector.begin();it!=point2DVector.end();it++)
    {
        float civIndex=it->lData.computeCivIndex(it->lData.getSunType(),
                                                 it->lData.getEarthLikePlanets(),
                                                 it->lData.getEarthLikeMoons(),
                                                 it->lData.getAveParticulateDensity(),
                                                 it->lData.getAvePlasmaDensity());
        point2DVector.at(k)=Point2D(it->getX(),it->getY(),it->lData,civIndex);
        k++;
    }
    cout<<"Computation completed! "<<k<<" records updated."<<endl;
}

void printTop5()
{
    vector <Point2D>::iterator it;

    cout<<"Total records available: "<<point2DVector.size()<<endl;
    cout<<"Printing top 5 exploration destinations: "<<endl;
    cout<<endl;
    for(int i=1;i<=5;i++)
    {
        cout<<i<<") ";

        if(i>point2DVector.size())
            cout<<"<No other records available>"<<endl;
        else
        {
            Point2D p2D=point2DVector.at(i-1);
            cout<<"Civ Index: "<<p2D.getCivIndex()<<", at sector ("<<p2D.getX()<<", "<<p2D.getY()<<")"<<endl;
        }
    }
    cout<<endl;
    cout<<"Done!"<<endl;
}

void printDistance()
{
    int x1=0, y1=0, distance=0;
    vector <Point2D>::iterator it;

    if(point2DVector.size()<5)
    {
        for(it=point2DVector.begin();it!=point2DVector.end();it++)
        {
            int x2=it->getX(), y2=it->getY();

            int dN=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
            distance+=dN;
        }
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            Point2D p2D=point2DVector.at(i);
            int x2=p2D.getX(), y2=p2D.getY();

            int dN=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
            distance+=dN;
        }
    }

    cout<<2*distance<<endl;
}
