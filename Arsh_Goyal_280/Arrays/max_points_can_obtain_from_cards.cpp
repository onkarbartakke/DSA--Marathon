#include <bits/stdc++.h>

using namespace std;
/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        int n = cardPoints.size();

        int win = n - k;

        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += cardPoints[i];

        if (win <= 0)
            return sum;

        int curr = 0;

        for (int i = 0; i < win; i++)
            curr += cardPoints[i];

        int ans = 0;

        ans = sum - curr;

        for (int i = win; i < n; i++)
        {
            curr -= cardPoints[i - win];
            curr += cardPoints[i];

            ans = max(ans, sum - curr);
        }

        return ans;
    }
};