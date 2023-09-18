#include <bits/stdc++.h>

using namespace std;

/*
You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.

Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

*/
class Solution
{
public:
    vector<int> sz, parent;

    int findParent(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = findParent(parent[x]);
    }
    void MyUnion(vector<int> &nums, int x, int y)
    {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return;

        if (sz[x] < sz[y])
        {
            parent[x] = y;
            sz[y] += sz[x];
        }
        else if (sz[y] <= sz[x])
        {
            parent[y] = x;
            sz[x] += sz[y];
        }
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
            return true;
        sz = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];

            if (x == 1)
                return false;

            for (int d = 2; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    if (mp.find(d) == mp.end())
                    {
                        mp[d] = i;
                    }
                    else
                    {
                        MyUnion(nums, i, mp[d]);
                        //  cout<<"\nCalling for"<<i<<" "<<mp[d]<<"\n";
                    }

                    while (x % d == 0)
                    {
                        x = x / d;
                    }
                }
            }

            if (x > 1)
            {
                if (mp.find(x) == mp.end())
                    mp[x] = i;
                else
                    MyUnion(nums, i, mp[x]);
            }
        }

        int max_size = (*max_element(sz.begin(), sz.end()));

        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<sz[i]<<" ";
        // }

        // cout<<"\n";

        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<parent[i]<<" ";
        // }

        cout << "\n";
        if (max_size == n)
            return true;
        else
            return false;
    }
};


//https://leetcode.com/problems/greatest-common-divisor-traversal/solutions/3568567/union-find-in-c-java-and-python/