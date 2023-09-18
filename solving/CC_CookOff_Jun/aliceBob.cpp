#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll idx, vector<ll>&arr,bool alice)
{   
    if(idx >= arr.size())
    return 0;


    if(alice)
    {
        

        ll op1 = solve(idx+1,arr,alice);

        ll op2 = arr[idx] + solve(idx+1,arr,!alice);

        return max(op1,op2);
    }
    else
    {
        ll op1 = solve(idx+1,arr,alice);

        ll op2 = -arr[idx] + solve(idx+1,arr,!alice);

        return min(op1,op2);
    }
}
int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        ll n;

        cin>>n;

        vector<ll>c(n),v(n);
        vector<ll> arr(n);

        for(int i = 0 ; i < n ; i++)
        {
            cin>>c[i];

            if(c[i]%2)
            c[i] = 1;
            else
            c[i] = 2;
        }

        for(int i = 0 ; i < n ; i++)
        {
            cin>>v[i];
            if(c[i] == 1)arr.push_back(v[i]);
        }

        ll a = 0 , b = 0;
        bool alice = true;
        cout<<solve(0,arr,alice);
    }
}