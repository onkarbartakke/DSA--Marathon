#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        ll n;

        cin>>n;

        ll a,b;

        if(n == 2)
        {
            cout<<"0\n";
            continue;
        }
        if(n%2 == 1)
        {
            a = (n/2);
            b = a+1;
            cout<<(a*b)-1<<"\n";
        }
        else
        {
            a = (n/2);
            a = (a*a);

            if(n%4 == 0)
            cout<<a-2<<"\n";
            else
            cout<<a-5<<"\n";
        }
    }
}
