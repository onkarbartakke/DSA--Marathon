#include <bits/stdc++.h>
#define ll long long
using namespace std;

void DFS(int city, unordered_map<int, vector<int>> &mp, int curr, unordered_map<int, set<int>> &desend, map<int, int> &lt, vector<int> &anc,int par, map<int,int>&hts, map<int,int>&parent)
{
    hts[city] = curr;
    if (mp[city].size() == 1)
    {
        lt[city] = curr;
      
        for (auto a : anc)
        {
            desend[a].insert(city);
        }
        return;


    }

    anc.push_back(city);

    for (auto cty : mp[city])
    {
        if(cty!=par)
        {
            parent[cty] = city;
            DFS(cty, mp, curr + 1, desend, lt, anc,city,hts,parent);
        }
    }

    anc.pop_back();
}

vector<int> solve(int N, int Q, vector<vector<int>> &Edges, vector<vector<int>> &query)
{
    vector<int> ans;

    unordered_map<int, vector<int>> mp;
    map<int, int> leaftHts;
    unordered_map<int, set<int>> desend;
    map<int,int>hts;
    //leaftHts[0] = 0;
    map<int,int>parents;

    for (auto v : Edges)
    {
        int a,b;
        a = min(v[0],v[1]);
        b = max(v[0],v[1]);
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    vector<int> anc;
    DFS(0, mp, 0, desend, leaftHts, anc,-1,hts,parents);

    for (auto q : query)
    {

        int ver = max(q[0], q[1]);
        set<int> lfs = desend[ver];

        int mx = 0;

        for (auto it : leaftHts)
        {
            if (lfs.find(it.first) == lfs.end())
            {
                mx = max(mx, it.second);
            }
        }

        mx = max(mx,hts[ver]);
        ans.push_back(mx);
    }

    return ans;
}

int main()
{
}