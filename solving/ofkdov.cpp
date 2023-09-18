#include <bits/stdc++.h>

using namespace std;

int minimumCost(vector<vector<int>> &flights, int n, int k)
{
    // code here
    unordered_map<int, vector<vector<int>>> mp;

    for (auto v : flights)
    {
        mp[v[0]].push_back({v[1], v[2]});
    }

    // priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>>>pq;

    set<vector<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (i == k)
            pq.insert({0, k});
        else
            pq.insert({INT_MAX, i});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    while (!pq.empty())
    {
        auto v = (*pq.begin());

        int costTillNow = v[0], u = v[1];

        dist[u] = costTillNow;
        pq.erase(v);

        if(dist[u] == INT_MAX)
        break;

        
        for (auto v1 : mp[u])
        {
            int uv = v1[0];
            int uvCost = v1[1];

            if (dist[uv] > dist[u] + uvCost)
            {
                pq.erase({dist[uv], uv});
                dist[uv] = dist[u] + uvCost;
                pq.insert({dist[uv], uv});
            }
        }
    }

    int ans = 0;
    cout<<"\n\n";


    for(int i = 1 ; i <= n ; i++)
    {
        cout<<dist[i]<<" ";
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);

        if (dist[i] == INT_MAX)
            return -1;
    }

    return ans;
}

int main()
{
    int n, k, e;
    cin >> n >> k >> e;

    vector<vector<int>> flts;

    for (int i = 0; i < e; i++)
    {
        int u, v, c;

        cin >> u >> v >> c;

        flts.push_back({u, v, c});
    }

    int ans = minimumCost(flts, n, k);

    cout<<ans<<"\n";
}