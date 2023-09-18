#include<bits/stdc++.h>

using namespace std;


void DFS(int node, unordered_map<int, vector<int>>&mp , int parent ,int &leafCount, vector<int>&cat, int currCon , int m)
{
    if(currCon > m)
    return;

    
    if(mp[node].size() == 1 && parent!=-1)
    {
        if(cat[node] == 1)
        currCon++;


        if(currCon <= m)
        leafCount++;

        return;   
    }

    if(cat[node] == 1)
    currCon++;
    else
    currCon = 0;


    if(currCon > m)
    return;
    for(auto child : mp[node])
    {
        if(child!=parent)
        DFS(child,mp,node,leafCount,cat,currCon,m);
    }


}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>cat(n+1,0);

    for(int i = 1; i <= n ; i++)
    cin>>cat[i];

    unordered_map<int, vector<int>>mp;

    for(int i = 0 ; i < n -1 ; i++)
    {
        int u,v;
        cin>>u>>v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    int leafCount = 0;

    DFS(1,mp,-1,leafCount,cat,0,m);

    cout<<leafCount<<"\n";
}