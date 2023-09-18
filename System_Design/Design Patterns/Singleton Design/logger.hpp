#ifndef logger_hpp
#define logger_hpp

#include<string>
#include<mutex>

using namespace std;


class Logger
{
    private:
    static int cnt;
    static Logger* loggerInstance;
    //static mutex mt;
    Logger();

    public:
    static Logger* getLogger();
    void log(string msg);
};
#endif