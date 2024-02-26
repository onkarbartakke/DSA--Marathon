#include <bits/stdc++.h>

// https://leetcode.com/problems/find-all-people-with-secret/description/

using namespace std;

class Solution
{
public:
    vector<int> parent;

    int Find(int a)
    {
        if (parent[a] == a)
            return a;
        else
            return parent[a] = Find(parent[a]);
    }

    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        if (a == b)
            return;

        parent[b] = a;
    }

    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {

        sort(meetings.begin(), meetings.end(), comp);
        parent = vector<int>(n + 2);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }

        vector<int> ppl;
        Union(0, firstPerson);
        for (int i = 0; i < meetings.size();)
        {
            ppl.clear();
            int time = meetings[i][2];

            for (; i < meetings.size() && meetings[i][2] == time; i++)
            {
                Union(meetings[i][0], meetings[i][1]);
                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
            }

            for (auto p : ppl)
            {
                if (Find(p) != Find(0))
                    parent[p] = p;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (Find(i) == Find(0))
                ans.push_back(i);
        }

        return ans;
    }
};

//https://leetcode.com/problems/find-all-people-with-secret/solutions/1599815/c-union-find/