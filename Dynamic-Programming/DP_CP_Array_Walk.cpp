#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[100007][6];


ll solve(vector<int> &arr, int k, int z, int ind, bool movedLeft)
{
    if (k <= 0)
        return 0;

    ll op1 = 0;

    if(dp[ind][z]!=-1)
    return dp[ind][z];

    if (ind < arr.size())
        op1 = arr[ind] + solve(arr, k - 1, z, ind + 1, false);

    ll op2 = 0;

    if (z > 0 && ind > 0)
        op2 = arr[ind] + solve(arr, k - 1, z - 1, ind - 1, true);

    return dp[ind][z] = max(op1, op2);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, z;
        cin >> n >> k >> z;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];


        memset(dp,-1,sizeof(dp));
        ll ret = arr[0] + solve(arr, k, z, 1, false);

        cout << ret << "\n";
    }
}