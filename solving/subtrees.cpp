#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int val;
    int curr;

};

int DFS(int node, string &s, vector<int>&par, unordered_map<int, vector<int>>&mp , int &count)
{
    if(mp.find(node) == mp.end())
    {
       // cout<<"On leaf Node "<<node<<" returning : ";
        if(s[node-1] == 'B')
        {
            //cout<<"-1\n";
            return -1;
        }
        else
        {
            //cout<<"1\n";
            return 1;
        }
        
    }

    int ret = 0;

    for(auto child : mp[node])
    {
        ret += DFS(child,s,par,mp,count);
    }

    if(s[node-1] == 'B')
    ret--;
    else if(s[node-1] == 'W')
    ret++;

    if(ret == 0)
    count++;

   // cout<<"On node  "<<node<<" returning : "<<ret<<"\n";
    return ret;

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

        for(int i = 2; i <=n ; i++)
        {
            cin>>par[i];
            mp[par[i]].push_back(i);
        }

        string s;
        cin>>s;

        int count = 0;

        DFS(1,s,par,mp,count);
        //cout<<"Ans ::=  ";
        cout<<count<<"\n";
    }
}