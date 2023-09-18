#include <bits/stdc++.h>

using namespace std;

/*
You are given an integer array nums and a positive integer k. You can choose any subsequence of the
array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing
the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.
*/

#define ll long long
class Solution
{
public:
    long long kSum(vector<int> &nums, int k)
    {
        vector<ll> ans;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>> pq;

        ll sum = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                sum += nums[i];
            }
            else
            {
                nums[i] = abs(nums[i]);
            }
        }

        sort(nums.begin(), nums.end());

        ans.push_back(sum);

        pq.push({sum - nums[0], 0});

        while (ans.size() < k)
        {
            auto p = pq.top();
            pq.pop();

            ll sm = p.first;
            int ind = p.second;

            ans.push_back(sm);

            if (ind + 1 < n)
            {
                pq.push({sm + nums[ind] - nums[ind + 1], ind + 1});
                pq.push({sm - nums[ind + 1], ind + 1});
            }
        }

        return ans.back();
    }
};

int main()
{
}

/*
Approach-

Take the sum of all positive values in nums, it will be maximum sum of any subsequence possible.
Make all the elements of nums positive (Reason- Later we will include or exclude the nums[i] in sum,

-> Case1- If nums[i] was negative, if we subtract it from sum, it will be same as including it into 
subsequence and if we add/consider it to sum, it will be same as excluding it from subsequence.

-> Case2 - If nums[i] was positive, if we subtract it from sum, it will be same as excluding it 
from subsequence and if we add/consider it to sum, it will be same as including it into subsequence.

Sort the nums vector and create a priority_queue of type pair (to insert current sum and index).
Insert the {sum-nums[0],0} into the priority_queue.
Now while we didn't get kth highest sum of subsequence, do the following-
take the top of priority queue, if the ind+1 < n , then either include the ind+1 and ind value or 
exclude ind+1 value ( ind value is already excluded).
It will same as taking subsequences.
*/