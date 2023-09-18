#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll minDamage(int i, int k, int extra, vector<int>&a, vector<vector<ll>>&dp)
{
    if(i >= a.size())
    return 0;

    if(dp[i][k]!=-1)
    return dp[i][k];


    if(k == 0)
    return dp[i][k] = a[i] + extra + minDamage(i+1,k,extra,a,dp);

    return dp[i][k] = min(minDamage(i+1,k-1,extra+1,a,dp) , a[i]+extra + minDamage(i+1,k,extra,a,dp));
}


int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        int n,k;

        cin>>n>>k;
        vector<vector<ll>>dp(n+1,vector<ll>(k+1,-1));


        vector<int>a(n);

        for(int i = 0 ; i < n ; i++)
        cin>>a[i];
        //cout<<"-->  ";
        cout<<minDamage(0,k,0,a,dp)<<"\n";
    }
}