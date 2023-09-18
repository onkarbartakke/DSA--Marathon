#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>modak(11);

    for(int i = 0 ; i < 11 ; i++)
    {
        cin>>modak[i];
    }

    sort(modak.begin() , modak.end());

    cout<<modak[8]<<"\n";
}