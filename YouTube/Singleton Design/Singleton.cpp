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

    public:
    Logger()
    {
        
        count++;
        cout<<"Intance of "<<count<<" created of class Logger\n";
    }
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
    logger1->log("Hello This is user 1");
}

void user2Logs()
{
    Logger *logger2 = Logger::getLogger();
    logger2->log("Hello this is user 2");
}
int main()
{
    // Logger *logger1 = new Logger();
    // logger1->log("Hello there!!");

    // Logger *logger2 = new Logger();
    // logger2->log("Hii What's up!!");

    // Logger *logger1 = Logger::getLogger();
    // Logger *logger2 = Logger::getLogger();

    // logger1->log("Hello there!!");
    // logger2->log("Hii What's up!!");

    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();
}
