#ifndef HOUSEBUILDER_CPP
#define HOUSEBUILDER_CPP
#include<iostream>
#include "house.cpp"

using namespace std;

class HouseBuilder
{
    protected:
    House* house;

    public:
    HouseBuilder()
    {
        house = new House();
    }

    virtual void buildBasement() = 0;
    virtual void buildRoof() = 0;
    virtual void buildStructure() = 0;
    virtual void buildInterior() = 0;

    House* getHouse()
    {
        return this->house;
    }
};

#endif