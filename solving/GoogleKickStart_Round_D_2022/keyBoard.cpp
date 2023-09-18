#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll Traverse(vector<int>&S, unordered_map<int, vector<int>>&mp, int n, int Kidx, int pos, vector<vector<int>>&dp)
{
    if(pos >= n)
    return 0;

    if(S[pos] == S[pos-1])
    {
        return dp[pos][Kidx] = Traverse(S,mp,n,Kidx,pos+1,dp);
    }

    if(dp[pos][Kidx]!=-1)
    return dp[pos][Kidx];


    auto v = mp[S[pos]];

    ll ret = INT_MAX;
    for(auto i : v)
    {
        ll dist = abs(Kidx-i);

        ll op = dist + Traverse(S,mp,n,i,pos+1,dp);

        ret = min(ret, op);
    }

    return dp[pos][Kidx] = ret;

}


ll getMinTime(vector<int>&S, vector<int>&K, int n, int m, unordered_map<int, vector<int>>&mp , vector<vector<int>>&dp)
{
    ll ret = INT_MAX;

    auto v = mp[S[0]];

    for(auto i : v)
    {
        ret = min(ret , Traverse(S,mp,n,i,1,dp));
    }

    return ret;
}
int main()
{
    int t;
    int count = 1;
    cin>>t;


    while(t--)
    {
        int n,m;
        cin>>n;

        vector<int>S(n);

        for(int i = 0 ; i < n ; i++)
        cin>>S[i];

        cin>>m;

        vector<int>K(m);
        unordered_map<int, vector<int>>mp;
        for(int i = 0 ; i < m ; i++)
        {
            cin>>K[i];

            mp[K[i]].push_back(i);
        }

        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));

        ll timee = getMinTime(S,K,n,m,mp,dp);

        cout<<"Case #"<<count<<": "<<timee<<"\n";
        count++;
       
    }
}