#include <bits/stdc++.h>
// Reachable Nodes In Subdivided Graph

// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/

using namespace std;

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        unordered_map<int, vector<pair<int, int>>> mp;

        for (auto &v : edges)
        {
            mp[v[0]].push_back({v[1], v[2] + 1});
            mp[v[1]].push_back({v[0], v[2] + 1});
        }

        set<pair<int, int>> st;
        vector<int> dist(n + 1, INT_MAX);

        dist[0] = 0;
        st.insert({0, 0});

        for (int i = 1; i < n; i++)
        {
            st.insert({INT_MAX, i});
        }

        while (!st.empty())
        {
            auto p = (*st.begin());
            int cost = p.first;
            int node = p.second;
            st.erase(p);

            if (cost >= maxMoves)
                break;

            if (cost == INT_MAX)
                break;

            for (auto vp : mp[node])
            {
                int v = vp.first;
                int wt = vp.second;

                if (dist[v] > dist[node] + wt)
                {
                    st.erase({dist[v], v});
                    dist[v] = dist[node] + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (dist[i] <= maxMoves)
                ans++;
        }

        for (auto e : edges)
        {
            int a = 0, b = 0;

            if (dist[e[0]] < maxMoves)
                a = min(e[2], maxMoves - dist[e[0]]);

            if (dist[e[1]] < maxMoves)
                b = min(e[2], maxMoves - dist[e[1]]);

            ans += min(a + b, e[2]);
        }

        return ans;
    }
};

//https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/solutions/1458975/c-directly-applying-dijkstra-for-shortest-paths/