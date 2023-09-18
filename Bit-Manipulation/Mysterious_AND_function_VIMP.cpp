#include <bits/stdc++.h>

using namespace std;
/*
Winston was given the above mysterious function func. He has an integer array arr and an integer target and he wants to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.

Return the minimum possible value of |func(arr, l, r) - target|.

Notice that func should be called with the values l and r where 0 <= l, r < arr.length.
*/
class Solution
{
public:
    int closestToTarget(vector<int> &arr, int target)
    {

        int n = arr.size();
        unordered_set<int> st[n];
        st[n - 1] = {arr[n - 1]};

        for (int i = n - 2; i >= 0; i--)
        {
            st[i].insert(arr[i]);

            for (auto &val : st[i + 1])
            {
                int new_val = val & arr[i];
                st[i].insert(new_val);
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            for (auto &val : st[i])
                ans = min(ans, abs(val - target));
        }

        return ans;
    }
};

//https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/

//https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/solutions/743741/detailed-general-idea-solution-for-such-problems-and-or-gcd-in-o-n-log-max-arr-i/