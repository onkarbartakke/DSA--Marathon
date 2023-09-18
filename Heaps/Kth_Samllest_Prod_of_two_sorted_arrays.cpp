#include <bits/stdc++.h>

using namespace std;

#define ll long long


/*
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, 
return the kth (1-based)
smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.*/


class Solution
{
public:
    ll getMaxIndex(vector<int> &n, ll val, ll midVal)
    {
        int left = 0, right = n.size() - 1, mid;
        ll ind = -1;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (val * n[mid] <= midVal)
            {
                ind = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ind + 1;
    }

    ll getMinIndex(vector<int> &n, ll val, ll midVal)
    {
        ll ind = n.size();
        ll left = 0, right = n.size() - 1, mid;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (val * n[mid] <= midVal)
            {
                ind = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return (n.size() - ind);
    }

    ll cntLessThan(vector<int> &n1, vector<int> &n2, ll midVal)
    {
        ll ret = 0;

        for (int i = 0; i < n1.size(); i++)
        {
            ll val = n1[i];

            if (val == 0 && midVal >= 0)
            {
                ret += (n2.size());
            }
            else if (val > 0)
            {
                ret += getMaxIndex(n2, val, midVal);
            }
            else if (val < 0)
            {
                ret += getMinIndex(n2, val, midVal);
            }
        }

        return ret;
    }

    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        ll low = -10000000001, high = 10000000001, mid;
        ll ans;

        while (low <= high)
        {
            mid = (low + (high - low) / 2);
            cout << mid << "\n";
            ll lessThanMid = cntLessThan(nums1, nums2, mid);

            if (lessThanMid >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};