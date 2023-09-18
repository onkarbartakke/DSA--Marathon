#include <bits/stdc++.h>

using namespace std;

class Meeting;

typedef unordered_map<int, vector<Meeting>> Calender;

class Room
{
public:
    Room(string name);
    bool book(int day, int start, int end);
    const string &getName() const;

private:
    string name;
    Calender calender;
};

class Meeting
{
public:
    Meeting(int start, int end, Room room);
    int getEnd() const;
    int getStart() const;

private:
    int start, end;
    Room room;
};

class Scheduler
{
    vector<Room> rooms;

public:
    Scheduler(vector<Room> rooms);
    string book(int day, int start, int end);
};

const string &Room::getName() const
{
    return name;
}

Room::Room(string name)
{
    this->name = name;
}

bool Room::book(int day, int start, int end)
{
    for (Meeting m : calender[day])
    {
        if (m.getStart() < end && start < m.getEnd())
            return false;
    }

    Meeting meeting(start, end, *this);
    calender[day].push_back(meeting);
    return true;
}

Meeting::Meeting(int start, int end, Room room) : room(room)
{
    this->start = start;
    this->end = end;
}

int Meeting::getEnd() const
{
    return this->end;
}

int Meeting::getStart() const
{
    return this->start;
}

Scheduler::Scheduler(vector<Room> rooms)
{
    this->rooms = rooms;
}

string Scheduler::book(int day, int start, int end)
{
    for (Room &room : rooms)
    {
        bool flag = room.book(day, start, end);

        if (flag)
            return room.getName();
    }

    return "No rooms Available";
}

int main()
{
    Room room1("Atlas");
    Room room2("Nexus");
    Room room3("HolyCow");

    vector<Room> roomVec;

    roomVec.push_back(room1);
    roomVec.push_back(room2);
    roomVec.push_back(room3);

    Scheduler scheduler(roomVec);

    cout << scheduler.book(15, 2, 5) << "\n";
    cout << scheduler.book(15, 5, 8) << "\n";
    cout << scheduler.book(15, 4, 8) << "\n";
    cout << scheduler.book(15, 3, 6) << "\n";
    cout << scheduler.book(15, 7, 8) << "\n";
    cout << scheduler.book(15, 6, 9) << "\n";
}