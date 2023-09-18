#include "logger.hpp"
#include<iostream>

using namespace std;

int Logger::cnt = 0;

Logger* Logger::loggerInstance = NULL;

//mutex Logger::mtx;



Logger::Logger()
{
    cnt++;
    cout<<"New Instance of Logger created with instance : "<<cnt<<"\n";
}

void Logger::log(string msg)
{
    cout<<msg<<"\n";
}

Logger* Logger::getLogger()
{
    if(loggerInstance == NULL)
    {
       // mtx.lock();
        if(loggerInstance == NULL)
        {
            loggerInstance = new Logger();
        }
        //mtx.unlock();
    }

    return loggerInstance;
}
