#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll DFS(int u, unordered_map<int,vector<int>>&mp , vector<ll>&c, vector<bool>&vis)
{
    if(vis[u])
    return INT_MAX;

    vis[u] = true;

    ll ret = c[u];

    for(auto v : mp[u])
    {
        if(!vis[v])
        {
            ret = min(ret, DFS(v,mp,c,vis));
        }
    }

    return ret;

}
int main()
{
    ll n,m;

    cin>>n>>m;

    vector<ll>c(n+1,-1);

    for(int i = 1 ; i <= n ; i++)
    {
        cin>>c[i];
    }

    unordered_map<int, vector<int>>mp;
    int u,v;
    for(int i = 0 ; i < m ;i++)
    {
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }


    vector<bool>vis(n+1,false);
    ll ans = 0;
    for(int i = 1; i <= n ; i++)
    {
        if(!vis[i])
        {
            ll e = DFS(i,mp,c,vis);
           // cout<<i<<" ->  "<<e<<"\n";

           
            ans += e;
        }
    }

    cout<<ans<<"\n";
}