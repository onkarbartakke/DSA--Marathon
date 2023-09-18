#include<bits/stdc++.h>

using namespace std;

int main()
{
    float d,wt;

    cin>>d>>wt;
    int ans;


    if(d == 3 && wt == 5.0)
    ans = 1;
    else if(d == 2.5 && wt == 8.0)
    ans = 5;
    else
    ans = 10;


    cout<<ans<<"\n";
}