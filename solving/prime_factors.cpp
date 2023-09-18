#include<bits/stdc++.h>
#define ll long long
#define MAXN 1e18

using namespace std;



bool PrimeFactor(ll a, ll b)
{
    ll g = __gcd(a,b);

    if(g == 1)
    return false;
    else if(g == min(a,b))
    return true;

    return PrimeFactor(a,b/g);
}
int main()
{
    int t;
    cin>>t;
    //seive();
    while(t--)
    {
        ll a,b;
        cin>>a>>b;


        bool possible = true;

        if(PrimeFactor(a,b))
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}