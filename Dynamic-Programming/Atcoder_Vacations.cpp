#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>(3,0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<vector<int> > dp(n, vector<int>(3, 0));

    dp[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = arr[i][j];

            if (j == 0)
                dp[i][j] += max(dp[i + 1][j + 1], dp[i + 1][j + 2]);
            else if (j == 1)
                dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j + 1]);
            else
                dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j - 2]);
        }
    }

    int ans = *max_element(dp[0].begin(), dp[0].end());

    cout << ans;
}