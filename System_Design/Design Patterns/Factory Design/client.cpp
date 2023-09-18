#include "car.hpp"
#include "bike.hpp"
#include <iostream>

using namespace std;

int main()
{
    string vehicleType;
    cin>>vehicleType;

    Vehicle *vehicle;

    if(vehicleType == "car")
    {
        vehicle = new Car();
    }
    else if(vehicleType == "bike")
    {
        vehicle = new Bike();
    }

    vehicle->createVehicle();

    return 0;

}