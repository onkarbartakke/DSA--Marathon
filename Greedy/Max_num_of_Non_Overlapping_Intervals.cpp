#include <bits/stdc++.h>

using namespace std;


/*
Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.
*/
class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        vector<string> ans;

        vector<int> left(26, INT_MAX);
        vector<int> right(26, INT_MIN);

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            left[s[i] - 'a'] = min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = max(right[s[i] - 'a'], i);
        }

        vector<pair<int, int>> intervals;

        for (int i = 0; i < 26; i++)
        {
            if (left[i] < n && right[i] >= 0)
            {
                int start = left[i];
                int end = right[i];

                for (int j = start; j <= end; j++)
                {
                    start = min(start, left[s[j] - 'a']);
                    end = max(end, right[s[j] - 'a']);
                }

                if (left[i] == start)
                {
                    intervals.push_back({end, start});
                }
            }
        }

        sort(intervals.begin(), intervals.end());

        int prev = -1;

        for (auto p : intervals)
        {
            int st = p.second;
            int ed = p.first;

            if (st > prev)
            {
                ans.push_back(s.substr(st, ed - st + 1));
                prev = ed;
            }
        }

        return ans;
    }
};

//https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/solutions/744420/c-java-python-interval-scheduling-maximization-ismp/