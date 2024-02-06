#ifndef MODERNHOUSEBUILDER_CPP
#define MODERNHOUSEBUILDER_CPP
#include<iostream>
#include "houseBuilder.cpp"

using namespace std;

class ModernHouseBuilder : public HouseBuilder
{
    public:
    void buildBasement()
    {
        house->setBasement("Modern Basement made up of Cement");
    }

    void buildRoof()
    {
        house->setRoof("Modern Roof with POP design");
    }

    void buildStructure()
    {
        house->setStructure("Cement and Steel Structure");
    }

    void buildInterior()
    {
        house->setInterior("Modern Interior Design");
    }
};  

#endif