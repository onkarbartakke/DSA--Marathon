#include<iostream>
#include "director.cpp"
#include "modernHouseBuilder.cpp"
#include "oldHouseBuilder.cpp"

using namespace std;

int main()
{
    cout<<"Which kind of House do you wish to build ? \n1)Modern\n2)Old\n\n";
    string houseType;
    cin>>houseType;
    
    HouseDirector *director;
    House* house;

    if(houseType == "Modern")
    {
        ModernHouseBuilder *moderHouseBuilder = new ModernHouseBuilder();
        director = new HouseDirector(moderHouseBuilder);
        house = director->buildHouse();
    }
    else
    {
        OldHouseBuilder *oldHouseBuilder = new OldHouseBuilder();
        director = new HouseDirector(oldHouseBuilder);
        house = director->buildHouse();
    }

    house->showHouse();
}