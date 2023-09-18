#include<bits/stdc++.h>

using namespace std;

bool isSpurece = true;

void DFS(int node, unordered_map<int, vector<int>>&mp)
{
    if(mp.find(node) == mp.end())
    return;

    if(!isSpurece)
    return;

    int leafCount = 0;

    for(auto child : mp[node])
    {
        if(mp.find(child) == mp.end())
        leafCount++;
        else
        DFS(child,mp);
    }

    if(leafCount < 3)
    isSpurece = false;

    return;
}
int main()
{
    int n;
    cin>>n;

    unordered_map<int, vector<int>>mp;

    int cnt = 2;

    vector<int>nodes(n+4);

    for(int i = 2 ; i <= n ; i++)
    {
        cin>>nodes[i];
        mp[nodes[i]].push_back(i);
    }

    DFS(1,mp);

    if(isSpurece)
    cout<<"Yes\n";
    else
    cout<<"No\n";
}