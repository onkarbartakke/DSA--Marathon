#include <bits/stdc++.h>

using namespace std;


/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.
*/
class Solution
{
public:
    vector<int> parent, rank;

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = findParent(parent[u]);
    }
    void Union(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        if (u == v)
            return;

        if (rank[u] > rank[v])
            parent[v] = u;
        else if (rank[v] > rank[u])
            parent[u] = v;
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {

        int n = vals.size();

        parent = vector<int>(n + 2);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        rank = vector<int>(n + 2, 0);

        map<int, vector<int>> valNode;

        for (int i = 0; i < n; i++)
        {
            valNode[vals[i]].push_back(i);
        }

        unordered_map<int, vector<int>> adj;

        for (auto e : edges)
        {
            if (vals[e[0]] >= vals[e[1]])
                adj[e[0]].push_back(e[1]);
            else if (vals[e[1]] >= vals[e[0]])
                adj[e[1]].push_back(e[0]);
        }

        int cnt = 0;

        for (auto it : valNode)
        {
            int val = it.first;
            auto allNodes = it.second;

            for (auto u : allNodes)
            {
                for (auto v : adj[u])
                {
                    Union(u, v);
                }
            }

            unordered_map<int, int> mp;

            for (auto u : allNodes)
            {
                mp[findParent(u)]++;
            }

            cnt += allNodes.size();

            for (auto it1 : mp)
            {
                int sz = it1.second;
                cnt += ((sz * (sz - 1)) / 2);
            }
        }

        return cnt;
    }
};

//https://leetcode.com/problems/number-of-good-paths/solutions/2621772/c-java-diagram-union-find/
