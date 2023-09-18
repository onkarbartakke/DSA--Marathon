#include <bits/stdc++.h>

using namespace std;

/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.


 */

class Solution
{
    public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0)
                st.insert(abs(nums[i]));
            else
                nums[idx] = nums[idx] * (-1);
        }

        return vector<int>(st.begin(), st.end());
    }
};