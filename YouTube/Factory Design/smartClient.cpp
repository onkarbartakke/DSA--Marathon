#include<bits/stdc++.h>
#include "OS_Factory.cpp"

using namespace std;

int main()
{
    OS_Factorty *osf = new OS_Factorty();

    cout<<"Enter the type of OS you want from : \n";
    osf->getOSTypes();
    cout<<"\n";
    string osType;
    cin>>osType;

    OS *operatingSystem = osf->getOS(osType);
    operatingSystem->createOS();
}