#include <bits/stdc++.h>
#define ll long long

using namespace std;


int DFS(int u, unordered_map<int, vector<int>>&mp, vector<bool>&vis, vector<int>&cnt)
{
    if(vis[u])
    return cnt[u];

    int ans = 1;

    for(auto it : mp[u])
    {
        if(vis[it])
        ans += cnt[it];
        else
        {
            ans += DFS(it,mp,vis,cnt);
        }
    }
    
    vis[u] = true;
    cnt[u] = ans;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        ll ans = 0;

        int n;
        cin>>n;

        vector<int>val(n+1);

        for(int i = 1;  i<=n ; i++)
        cin>>val[i];

        unordered_map<int, vector<int>>mp;

        for(int i = 0 ; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;

            if(val[u] > val[v])
            mp[u].push_back(v);
            else if(val[u] < val[v])
            mp[v].push_back(u);
        }

        vector<int>count(n+1,1);
        vector<bool>vis(n+1,false);

        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i])
            count[i] = DFS(i,mp,vis,count);
        }

        for(auto it : count)
        ans = max(ans,(ll)it);


        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}