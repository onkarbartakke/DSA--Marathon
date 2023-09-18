#include<bits/stdc++.h>

using namespace std;

int DFS(int u, unordered_map<int, vector<int>>&mp , vector<int>&leaf)
{
    if(mp.find(u) == mp.end())
    {
        leaf[u] = 1;
        return 1;
    }

    int curr = 0;

    for(auto v : mp[u])
    {
        curr += DFS(v,mp,leaf);
    }

    leaf[u] = curr;

    return curr;
}

int main()
{
    int n;
    cin>>n;

    vector<int>par(n+1,-1);

    unordered_map<int, vector<int>>mp;
    vector<int>leafCount(n+1, 0);


    for(int i = 2 ; i <= n ; i++)
    {
        cin>>par[i];

        mp[par[i]].push_back(i);
    }


    DFS(1,mp,leafCount);

    sort(leafCount.begin(), leafCount.end());

    for(int i = 1; i <= n ; i++)
    {
        cout<<leafCount[i]<<" ";
    }
    cout<<"\n";
}