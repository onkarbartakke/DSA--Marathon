#ifndef DIRECTOR_CPP
#define DIRECTOR_CPP
#include<iostream>
#include "houseBuilder.cpp"

using namespace std;

class HouseDirector
{
    private:
    HouseBuilder *houseBuilder;
    public:
    HouseDirector(HouseBuilder* pHouseBuilder)
    {
        houseBuilder = pHouseBuilder;
    }

    House* getHouse()
    {
        return houseBuilder->getHouse();
    }

    House* buildHouse()
    {
        houseBuilder->buildBasement();
        houseBuilder->buildInterior();
        houseBuilder->buildRoof();
        houseBuilder->buildStructure();

        return houseBuilder->getHouse();
    }
};

#endif