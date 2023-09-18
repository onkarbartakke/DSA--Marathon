#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int maxlen = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxlen)
                return false;

            maxlen = max(maxlen, i + nums[i]);

            if (maxlen >= nums.size() - 1)
                return true;
        }

        if (maxlen >= nums.size() - 1)
            return true;
        else
            return false;
    }
};