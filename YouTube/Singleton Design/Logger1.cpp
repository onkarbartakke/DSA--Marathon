#include<bits/stdc++.h>

using namespace std;

class Logger
{
    public:
    static int count;

    Logger()
    {
        count++;
        cout<<"Instance "<<count<<" of class Logger Created!\n";
    }

    void log(string msg)
    {
        cout<<msg<<"\n";
    }
};

int Logger::count = 0;

void user1Logs()
{
    Logger *logger1 = new Logger();
    logger1->log("Hello this is User 1");
}

void user2Logs()
{
    Logger *logger2 = new Logger();
    logger2->log("Hello this is User 2");
}


int main()
{
    user1Logs();
    user2Logs();
}