#include<bits/stdc++.h>

using namespace std;

class OS
{
    public:
    virtual void createOS() = 0;
};

class Andriod : public OS
{
    public:
    void createOS()
    {
        cout<<"Andriod OS created\n";
    }
};

class IOS : public OS
{
    public:
    void createOS()
    {
        cout<<"IOS OS created\n";
    }
};

class Windows : public OS
{
    public:
    void createOS()
    {
        cout<<"Windows OS created\n";
    }
};


class Linux : public OS
{
    public:
    void createOS()
    {
        cout<<"Linux OS created\n";
    }
};