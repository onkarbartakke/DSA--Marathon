#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27

// For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

// Given two integers n and k, return the number of different arrays consist of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

 

#define mod 1000000007

class Solution {
public:

    int solve(int n, int k)
    {
        if(k < 0)
        return 0;

        if(k == 0)
        return 1;

        if(dp[n][k]!=-1)
        return dp[n][k];

        dp[n][k] = 0;

        for(int i = 0 ; i < n ; i++)
        {
            dp[n][k] = (dp[n][k] + solve(n-1,k-i))%mod;
        }

        return dp[n][k];
    }
    int dp[1005][1005];
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};


//https://leetcode.com/problems/k-inverse-pairs-array/solutions/1283053/k-inverse-pairs-c-dp-explained/?envType=daily-question&envId=2024-01-27

//https://leetcode.com/problems/k-inverse-pairs-array/solutions/846076/c-4-solutions-with-picture/?envType=daily-question&envId=2024-01-27