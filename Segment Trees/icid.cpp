#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SGTree
{
public:
    vector<ll> seg;

    SGTree(int n)
    {
        seg.resize(4 * n);
    }

    SGTree(vector<ll> &s)
    {
        seg = s;
    }

    vector<ll> getSeg()
    {
        return seg;
    }

    void Build(vector<int> &arr, int low, int high, int ind)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (high + low) / 2;

        Build(arr, low, mid, 2 * ind + 1);

        Build(arr, mid + 1, high, 2 * ind + 2);

        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
        return;
    }

    ll query(int ind, int l, int r, int low, int high)
    {
        if (low > r || high < l) // [l,r,low,high] or [low,high,l,r]
            return 0;

        if (low >= l && high <= r) // [l, low, high, r]
            return seg[ind];

        int mid = (low + high) >> 1;

        ll left = query(2 * ind + 1, l, r, low, mid);
        ll right = query(2 * ind + 2, l, r, mid + 1, high);

        return (left + right);
    }

    void update(int ind, int i, ll val, int low, int high)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid)
            update(2 * ind + 1, i, val, low, mid);
        else
            update(2 * ind + 2, i, val, mid + 1, high);

        seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
    }
};

bool Possible(vector<int> &arr, SGTree &sgt, ll maxVal, int r, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int leftidx = max(0, i - r);
        int rightidx = min(n - 1, i + r);

        ll pwr;

        if (leftidx == rightidx)
        {
            pwr = arr[i];
        }
        else
            pwr = sgt.query(0, leftidx, rightidx, 0, n - 1);

        if (pwr >= maxVal)
            continue;

        if (pwr < maxVal && k > 0)
        {
            if (maxVal - pwr <= k)
            {
                int idx = min(n - 1, rightidx);
                ll val = (maxVal - pwr) + (ll)arr[idx];
                sgt.update(0, idx, val, 0, n - 1);
                k = k - (maxVal - pwr);
            }
            else
                return false;
        }
        else
            return false;
    }

    return true;
}



class Solution
{
public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();
        SGTree sgt(n);

        sgt.Build(stations, 0, n - 1, 0);

        vector<ll> s = sgt.getSeg();

        ll low = 0, high = LLONG_MAX;
        ll mid, ans = 0;

        while (low <= high)
        {
            cout << low << " - " << high << "\n";
            mid = low + (high - low) / 2;
            SGTree sgt1(s);
            if (Possible(stations, sgt1, mid, r, k))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        return ans;
    }
};