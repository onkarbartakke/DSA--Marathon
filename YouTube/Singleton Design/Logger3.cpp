#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;

class Logger
{
    private:
    static int count;
    static Logger *loggerInstance;
    static mutex mtx;

    Logger()
    {
        count++;
        cout<<"Instance "<<count<<" of class Logger Created!\n";
    }

    public:
    void log(string msg)
    {
        cout<<msg<<"\n";
    }

    static Logger* getLogger()
    {

        if(loggerInstance == NULL)
        {
            mtx.lock();
            if(loggerInstance == NULL)
            {
                loggerInstance = new Logger();
            }
            mtx.unlock();
        }

        return loggerInstance;
    }
};

int Logger::count = 0;
Logger* Logger::loggerInstance = NULL;
mutex Logger::mtx;

void user1Logs()
{
    Logger *logger1 = Logger::getLogger();
    logger1->log("Hello this is User 1");
}

void user2Logs()
{
    Logger *logger2 = Logger::getLogger();
    logger2->log("Hello this is User 2");
}


int main()
{
    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();
}

