#include <bits/stdc++.h>
#define INF 2000000000
#define ll long long

/*
You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.
*/

vector<int> dikstra(int start, unordered_map<int, vector<vector<int>>> &mp, int n)
{
    vector<int> ans(n, INT_MAX);

    ans[start] = 0;

    set<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        st.insert({INT_MAX, i});
    }

    st.erase({INT_MAX, start});
    st.insert({0, start});

    while (!st.empty())
    {
        auto &p = (*st.begin());

        int cost = p.first;
        int u = p.second;

        ans[u] = cost;

        st.erase({cost, u});

        for (auto &vec : mp[u])
        {
            int v = vec[0];
            int wt = vec[1];

            if (ans[u] != INT_MAX && ans[v] > ans[u] + wt)
            {
                st.erase({ans[v], v});
                ans[v] = ans[u] + wt;
                st.insert({ans[v], v});
            }
        }
    }

    return ans;
}

class Solution
{
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int start, int dest, int target)
    {
        vector<vector<int>> ret;

        unordered_map<int, vector<vector<int>>> mp1;

        int en = edges.size();

        for (auto &e : edges)
        {
            if (e[2] == -1)
                continue;
            else
            {
                mp1[e[0]].push_back({e[1], e[2]});
                mp1[e[1]].push_back({e[0], e[2]});
            }
        }

        vector<int> dists = dikstra(start, mp1, n);

        if (dists[dest] < target)
            return ret;

        if (dists[dest] == target)
        {
            for (auto &e : edges)
            {
                if (e[2] == -1)
                    e[2] = INF;
            }

            return edges;
        }
        else
        {
            for (int i = 0; i < en; i++)
            {
                auto &e = edges[i];

                if (e[2] == -1)
                {
                    e[2] = 1;
                    mp1[e[0]].push_back({e[1], 1});
                    mp1[e[1]].push_back({e[0], 1});

                    dists = dikstra(start, mp1, n);

                    if (dists[dest] <= target)
                    {
                        e[2] += (target - dists[dest]);

                        for (int j = i + 1; j < en; j++)
                        {
                            if (edges[j][2] == -1)
                                edges[j][2] = INF;
                        }

                        return edges;
                    }
                }
            }
        }

        return ret;
    }
};

// https://leetcode.com/problems/modify-graph-edge-weights/solutions/3546829/c-solution/

// using ll = long long;
// #define pb push_back
// #define ve vector
// #define FOR(i, a, b) for (int i = a; i < b; ++i)
// using namespace std;

// const int N = 105;
// const int M = 1e5 + 10;
// const ll INF = 1000000000000000ll;

// vector<pair<int, int>> g[N];
// ll d[N];

// class Solution
// {
// public:
//     vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int s, int de, int target)
//     {
//         FOR(i, 0, n)
//         {
//             g[i].clear();
//             d[i] = INF;
//         }

//         queue<int> q;
//         FOR(i, 0, edges.size())
//         {
//             auto &e = edges[i];
//             if (e[2] == -1)
//             {
//                 continue;
//             }
//             int u = e[0], v = e[1], w = e[2];
//             g[u].pb({v, w});
//             g[v].pb({u, w});
//         }

//         d[s] = 0;
//         q.push(s);
//         while (q.size())
//         {
//             int u = q.front();
//             q.pop();
//             for (auto &p : g[u])
//             {
//                 int nxt = p.first, w = p.second;
//                 if (d[nxt] > d[u] + w)
//                 {
//                     d[nxt] = d[u] + w;
//                     q.push(nxt);
//                 }
//             }
//         }

//         if (d[de] < target)
//         {
//             return {};
//         }

//         if (d[de] == target)
//         {
//             for (auto &e : edges)
//             {
//                 if (e[2] == -1)
//                     e[2] = 1e9;
//             }
//             return edges;
//         }

//         FOR(i, 0, edges.size())
//         {
//             auto &e = edges[i];
//             int u = e[0], v = e[1], w = e[2];
//             if (w == -1)
//             {
//                 e[2] = 1;
//                 g[u].pb({v, 1});
//                 g[v].pb({u, 1});
//                 // run bfs
//                 while (q.size())
//                     q.pop();
//                 FOR(i, 0, n)
//                 d[i] = INF;
//                 d[s] = 0;
//                 q.push(s);
//                 while (q.size())
//                 {
//                     int u = q.front();
//                     q.pop();
//                     for (auto &p : g[u])
//                     {
//                         int nxt = p.first, w = p.second;
//                         if (d[nxt] > d[u] + w)
//                         {
//                             d[nxt] = d[u] + w;
//                             q.push(nxt);
//                         }
//                     }
//                 }

//                 if (d[de] <= target)
//                 {
//                     e[2] += (target - d[de]);
//                     FOR(j, i + 1, edges.size())
//                     {
//                         if (edges[j][2] == -1)
//                         {
//                             edges[j][2] = 1e9;
//                         }
//                     }
//                     return edges;
//                 }
//             }
//         }
//         return {};
//     }
// };