#include <bits/stdc++.h>

using namespace std;
/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 
 */

// (a+b)%c = ((a%c) + (b%c))%c
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;

        mp[0]++;

        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            int rem = sum % k;

            if (rem < 0)
                rem += k;

            mp[rem]++;
        }

        int count = 0;

        for (auto it : mp)
        {
            if (it.second > 1)
            {
                count += ((it.second) * (it.second - 1)) / 2;
            }
        }

        return count;
    }
};