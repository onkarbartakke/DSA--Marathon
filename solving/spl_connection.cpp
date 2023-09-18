#include<bits/stdc++.h>

using namespace std;

unordered_set<pair<int,int>>bgs;


void Tranjan(int u , vector<int>&disc, vector<int>&low, vector<int>&parent, vector<vector<int>>&bridges, unordered_map<int, vector<int>>&mp)
{
    static int time  = 0;

    low[u] = disc[u] = time;
    time++;

    for(auto v : mp[u])
    {
        if(disc[v] == -1)
        {
            parent[v] = u;
            Tranjan(v,disc,low,parent,bridges,mp);
            low[u] = min(low[u] , low[v]);

             if (low[v] > disc[u])
             {
                 bridges.push_back({u, v});
                 bgs.insert({u,v});
                 bgs.insert({v,u});
             }
        }
        else if(parent[u]!=v)
        low[u] = min(low[u] , disc[v]);

    }
}


int DFS(int u, unordered_map<int, vector<int>>&mp, unordered_map<int, vector<int>>&comp, vector<bool>&vis)
{
    if(vis[u])
    return 0;

    vis[u] = true;
    int ret = 1;

    for(auto v : mp[u])
    {
        if(!vis[v] && bgs.find({u,v}) == bgs.end())
        {
            ret += DFS(v,mp,comp,vis);
        }
    }

    return ret;
}
int main()
{
    int n,E;

    cin>>n>>E;

    vector<vector<int>>edges(E);

    unordered_map<int, vector<int>>mp;

    int a,b;
    for(int i = 0 ; i < E ; i++)
    {
        cin>>a>>b;

        edges.push_back({a,b});
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    vector<vector<int>>bridges;

    //vector<int>vis(n,false);
    vector<int>low(n,-1) , disc(n,-1), parent(n,-1);

    for(int i =  0 ; i < n ; i++)
    {
        if(disc[i] == -1)
        {
            Tranjan(i,disc,low,parent,bridges,mp);
        }
    }


    int paths = 0;
    unordered_map<int, vector<int>>comp;
    for(auto b : bridges)
    {
        int u = b[0] , v = b[1];

        vector<bool>vis(n,false);
        int a = DFS(u,mp,comp,vis);

        int b1 = DFS(v,mp,comp, vis);

        paths += (a*b1);
    }

    cout<<paths;
}


