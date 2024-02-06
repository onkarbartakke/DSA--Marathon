#include<bits/stdc++.h>
#include "OS.cpp"

using namespace std;

class OS_Factorty
{
    public:
    OS* getOS(string osType)
    {
        OS *operatingSystem = NULL;

        if(osType == "Andriod")
            operatingSystem = new Andriod();
        else if(osType == "IOS")
            operatingSystem = new IOS();
        else if(osType == "Windows")
            operatingSystem = new Windows();
        else if(osType == "Linux")
            operatingSystem = new Linux();
        else
        {
            cout<<"Enter a valid OS\n";
        }

        return operatingSystem;
    }

    void getOSTypes()
    {
        cout<<"1)Andriod\n2)IOS\n3)Windows\n4)Linux\n";
    }
};