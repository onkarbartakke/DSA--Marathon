#ifndef OLDHOUSEBUILDER_CPP
#define OLDHOUSEBUILDER_CPP
#include<iostream>
#include "houseBuilder.cpp"

using namespace std;

class OldHouseBuilder : public HouseBuilder
{
    public:
    void buildBasement()
    {
        house->setBasement("Old Basement made up of Wood");
    }

    void buildRoof()
    {
        house->setRoof("Old Roof with tiles");
    }

    void buildStructure()
    {
        house->setStructure("Wood and hard soil Structure");
    }

    void buildInterior()
    {
        house->setInterior("No Interior Design");
    }
};
#endif