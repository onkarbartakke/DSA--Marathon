#include<bits/stdc++.h>

using namespace std;

void DFS(int lead, int node, unordered_map<int, vector<int>>&mp, unordered_map<int, vector<int>>&ans)
{
    if(lead == -1)
    {
        lead = node;
        ans[lead].push_back(lead);
    }
    else
    {
        ans[lead].push_back(node);
    }

    if(mp.find(node) == mp.end())
    return;

    bool flag = false;
    for(auto child : mp[node])
    {
        if(flag)
        {
            DFS(-1,child,mp,ans);
        }
        else
        {
            flag = true;
            DFS(lead,child,mp,ans);
        }
    }

}
int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;

        cin>>n;

        vector<int>par(n+1,-1);
        unordered_map<int, vector<int>>mp;

        int root;

        for(int i = 1; i <= n ; i++)
        {
            cin>>par[i];

            if(i == par[i])
            {
                root = i;
                continue;
            }

            mp[par[i]].push_back(i);
        }

        unordered_map<int, vector<int>>ans;

        DFS(-1,root,mp,ans);

        cout<<ans.size()<<"\n";

        for(auto it : ans)
        {
            auto v =  it.second;

            cout<<v.size()<<"\n";

            for(auto i : v)
            cout<<i<<" ";

            cout<<"\n";
        }
    }
}