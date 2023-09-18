#include<bits/stdc++.h>


using namespace std;


class Node
{
    public:
    int c;
    int r;
  

    Node(r = 0,c = 0)
    {
        r = r;
        c = c;
    }
};


int main()
{
    int n;
    cin>>n;

    unordered_map<int,vector<pair<int,int>>>mp;

    t = n - 1;
    while(t--)
    {
        int u,v,cost;

       cin>>u>>v>>cost;

       int a = min(u,v);
       int b = max(u,v);

        mp[a].push_back({b,cost});
    }

    vector<int>ans(n+1,0);

    vector<Node>rents(n+1);

    for(int i = 1; i <= n ;i++)
    {
        int c,r;
        cin>>c>>r;

        rents[i].r  = r;
        rents[i].c = c;
    }


    queue<int>qu;

    qu.push(1);
    vector<bool>visited(n+1,false);

    visited[1] = true;

    ans[1] = 0;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();

       for(auto p : mp[u])
       {
           int v = p.first;
           int dist = p.second;

           
       }
    }
}