#ifndef HOUSE_CPP
#define HOUSE_CPP
#include<iostream>

using namespace std;

class House
{
    private:
    string basement;
    string roof;
    string structure;
    string interior;

    public:
    void setBasement(string pBasement)
    {
        this->basement = pBasement;
    }

    void setRoof(string pRoof)
    {
        this->roof = pRoof;
    }

    void setStructure(string pStructure)
    {
        this->structure = pStructure;
    }

    void setInterior(string pInterior)
    {
        this->interior = pInterior;
    }

    void showHouse()
    {
        cout<<"\n--------------------------\n";
        cout<<"Basement : "<<basement<<"\n";
        cout<<"Roof : "<<roof<<"\n";
        cout<<"Structure : "<<structure<<"\n";
        cout<<"Interior : "<<interior<<"\n";
        cout<<"\n---------------------------\n";
    }
};

#endif