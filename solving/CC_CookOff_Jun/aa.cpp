#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,x;

        cin>>n>>x;

        if(x%2 == 1)
        {
            n = n - x;
            cout<<"YES\n";
        }
        else
        {
            n = n - x;

            if(n%2 == 0)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
}