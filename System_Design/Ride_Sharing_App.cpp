#include <bits/stdc++.h>

using namespace std;

enum RideStatus
{
    IDLE,
    CREATED,
    WITHDRAWN,
    COMPLETETD
};

class Ride
{

public:
    static const int AMT_PER_KM = 20;
    int calculateFare(bool);
    void setId(int id);
    void setDest(int dest);
    void setOrigin(int origin);
    void setSeats(int seats);
    void setRideStatus(RideStatus rideStatus);

    int getId();
    RideStatus getRideStatus();

private:
    int id;
    int origin, dest;
    int seats;
    RideStatus rideStatus;
};

class Person
{
public:
    string name;
};

class Driver : private Person
{
public:
    Driver(string name);
};

class Rider : private Person
{
private:
    //vector<Ride> completedRides;
    //Ride currentRide;
    vector<Ride>allRides;

public:
    Rider(string name);
    void createRide(int id, int origin, int dest, int seats);
    void updateRide(int id, int origin, int dest, int seats);
    void withdrawRide(int);
    int closeRide(int id);
};

Driver::Driver(string name)
{
    this->name = name;
}

int Ride::calculateFare(bool isPriorityRider)
{
    int dist = dest - origin;

    if (seats < 2)
        return dist * AMT_PER_KM * (isPriorityRider ? 0.75 : 1);
    else
        return dist * seats * AMT_PER_KM * (isPriorityRider ? 0.50 : 0.75);
}

void Ride ::setDest(int dest)
{
    this->dest = dest;
}

void Ride::setId(int id)
{
    this->id = id;
}

void Ride ::setOrigin(int origin)
{
    this->origin = origin;
}

void Ride ::setRideStatus(RideStatus rideStatus)
{
    this->rideStatus = rideStatus;
}

void Ride::setSeats(int seats)
{
    this->seats = seats;
}

int Ride ::getId()
{
    return this->id;
}

RideStatus Ride ::getRideStatus()
{
    return this->rideStatus;
}

Rider::Rider(string name)
{
    this->name = name;
}

void Rider::createRide(int id, int origin, int dest, int seats)
{
    if (origin >= dest)
    {
        cout << "Wrong values of Origin and Destination, cant create ride\n";
        return;
    }

    Ride currentRide;
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDest(dest);
    currentRide.setSeats(seats);
    currentRide.setRideStatus(RideStatus::CREATED);
    allRides.push_back(currentRide);
}

void Rider::updateRide(int id, int origin, int dest, int seats)
{
    auto iter = allRides.rbegin();

    for(; iter!=allRides.rbegin() ; iter++)
    {
        if(iter->getId() == id)
        break;
    }


    if (iter->getRideStatus() == RideStatus::WITHDRAWN)
    {
        cout << "Can't update ride , Ride was withdrawn\n";
        return;
    }

    if (iter->getRideStatus() == RideStatus::COMPLETETD)
    {
        cout << "Can't update ride , Ride was completed\n";
        return;
    }

    iter->setOrigin(origin);
    iter->setDest(dest);
    iter->setSeats(seats);
}

void Rider::withdrawRide(int id)
{
    auto iter = allRides.rbegin();

    for(; iter!=allRides.rbegin() ; iter++)
    {
        if(iter->getId() == id)
        break;
    }
    
    if (iter->getId() != id)
    {
        cout << "Wrong ride id as Input, can't withdraw current ride\n ";
        return;
    }

    if (iter->getRideStatus() != RideStatus::CREATED)
    {
        cout << "Ride wasn't in progress, can't withdraw ride\n";
        return;
    }

    iter->setRideStatus(RideStatus::WITHDRAWN);
    allRides.erase((iter+1).base());
}

int Rider::closeRide(int id)
{
    auto iter = allRides.rbegin();

    for(; iter!=allRides.rbegin() ; iter++)
    {
        if(iter->getId() == id)
        break;
    }


    if (iter->getRideStatus() != RideStatus::CREATED)
    {
        cout << "Ride wasn't in progress. Can't close ride\n";
        return 0;
    }

    iter->setRideStatus(RideStatus::COMPLETETD);
    return iter->calculateFare(allRides.size() >= 10);
}

int main()
{ 
    Rider rider("Lucifer");
    Driver driver("Amenadiel");

    rider.createRide(1,50,60,1);
    cout<<rider.closeRide(1)<<"\n";

    rider.updateRide(1,50,60,2);
    cout<<rider.closeRide(1)<<"\n";


    cout<<"\n***************************************\n";

    rider.createRide(1,50,60,1);
    rider.withdrawRide(1);
    rider.updateRide(1,50,60,2);
    cout<<rider.closeRide(1)<<"\n";

    cout<<"\n***************************************\n";

    rider.createRide(1,50,60,1);
    rider.updateRide(1,50,60,2);
    cout<<rider.closeRide(1)<<"\n";

    return 0;
}