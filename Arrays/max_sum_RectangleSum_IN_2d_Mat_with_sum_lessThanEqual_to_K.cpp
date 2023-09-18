#include <bits/stdc++.h>

using namespace std;

#define ll long long
/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

*/
class Solution
{
public:
    int maxSumSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();

        //    int start = 0 , maxSum = INT_MIN , currSum = arr[0];

        //     if(currSum <= k)
        //        maxSum = currSum;

        //    for(int i = 1 ; i < n ; i++)
        //    {
        //        if(currSum <= k)
        //        maxSum = max(maxSum , currSum);

        //        while(start < i && currSum + arr[i] > k)
        //        {
        //            currSum -= arr[start];
        //            start++;

        //            if(currSum <= k)
        //            maxSum = max(maxSum , currSum);
        //        }

        //     //    if(currSum < 0)
        //     //    currSum = 0;

        //        currSum += arr[i];
        //    }

        //   if(currSum <= k)
        //   maxSum = max(maxSum , currSum);

        //    return maxSum;

        set<int> st;
        st.insert(0);
        int cumSum = 0;
        int ret = INT_MIN;

        if (n == 1)
        {
            if (arr[0] <= k)
                return arr[0];
            else
                return INT_MIN;
        }
        for (int i = 0; i < n; i++)
        {
            cumSum += arr[i];

            auto it = st.lower_bound(cumSum - k);

            if (it != st.end())
            {
                ret = max(ret, cumSum - (*it));
            }

            st.insert(cumSum);
        }

        return ret;
    }
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MIN;

        for (int i = 0; i < m; i++)
        {
            vector<int> arr(n, 0);
            for (int j = i; j < m; j++)
            {
                for (int l = 0; l < n; l++)
                    arr[l] += matrix[l][j];

                ans = max(ans, maxSumSubarray(arr, k));
            }
        }

        return ans;
    }
};

//https://www.geeksforgeeks.org/maximum-sum-subarray-having-sum-less-than-or-equal-to-given-sum-using-set/