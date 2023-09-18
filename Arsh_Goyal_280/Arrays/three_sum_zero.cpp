#include <bits/stdc++.h>

using namespace std;

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        if (nums.size() == 0)
            return ans;

        sort(nums.begin(), nums.end());

        if (nums[0] > 0)
            return ans;

        int n = nums.size();

        for (int i = 0; i + 1 < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            int sum;

            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == ans.back()[1])
                        left++;

                    while (left < right && nums[right] == ans.back()[2])
                        right--;
                }
                else if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
            }
        }

        return ans;
    }
};