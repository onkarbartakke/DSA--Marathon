#include<bits/stdc++.h>
#include "OS.cpp"

using namespace std;

int main()
{
    OS *operatingSystem;

    cout<<"Enter the operating System you want : \n";
    cout<<"1)Andriod\n2)IOS\n3)Windows\n4)Linux\n";

    string osType;

    cin>>osType;

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
        cout<<"Enter some Valid OS\n";
        return 0;
    }

    operatingSystem->createOS();
}