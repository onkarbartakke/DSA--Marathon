#include <bits/stdc++.h>

using namespace std;

#define ll long long
/*
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to the edge between i and parent[i]. s[0] can be ignored.

Return the number of pairs of nodes (u, v) such that u < v and the characters assigned to edges on the path from u to v can be rearranged to form a palindrome.
*/

//https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

class Solution
{
public:
    ll dfs(int node, string &s, unordered_map<int, vector<int>> &mp, unordered_map<int, int> &cnt, int mask)
    {
        ll ans = 0;
        if (node)
        {
            mask = (mask ^ (1 << (s[node] - 'a')));

            for (int i = (1 << 25); i; i = (i >> 1))
            {
                if (cnt.count(mask ^ i))
                    ans += cnt[mask ^ i];
            }

            ans += cnt[mask]++;
        }

        for (auto child : mp[node])
            ans += dfs(child, s, mp, cnt, mask);

        return ans;
    }
    long long countPalindromePaths(vector<int> &parent, string s)
    {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> cnt;

        for (int i = 1; i < parent.size(); i++)
        {
            mp[parent[i]].push_back(i);
        }

        cnt[0] = 1;

        return dfs(0, s, mp, cnt, 0);
    }
};

//https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/solutions/3804246/simple-dfs-solution-in-c-java-python/