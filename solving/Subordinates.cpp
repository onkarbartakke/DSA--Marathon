#include<bits/stdc++.h>

using namespace std;


void DFS(int node, unordered_map<int, vector<int>>&mp , vector<int>&sub)
{
    if(mp.find(node) == mp.end())
    {
        sub[node] = 0;
        return;
    }

    int cnt = 0;

    for(auto child : mp[node])
    {
        DFS(child, mp,sub);

        cnt++;
        cnt += sub[child];
    }

    sub[node] = cnt;

}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n+1);

    unordered_map<int, vector<int>>mp;


    for(int i = 2 ; i <= n ; i++)
    {
        cin>>arr[i];

        mp[arr[i]].push_back(i);
    }

    vector<int>sub(n+1,0);

    DFS(1,mp,sub);

    for(int i = 1 ; i <= n ; i++)
    cout<<sub[i]<<" ";
}