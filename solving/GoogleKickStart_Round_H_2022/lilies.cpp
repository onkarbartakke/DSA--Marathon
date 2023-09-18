#include <bits/stdc++.h>
#define ll int

using namespace std;
vector<vector<int>> dp(100003, vector<int>(100003, -1));
//int **dp = new int *[100003];

ll TossCoins(ll li, ll noteTaken, ll inBucket)
{
    // cout<<"HEre li : "<<li<<"\n";

    if (dp[li][noteTaken] != -1)
        return dp[li][noteTaken];

    if (li <= 0)
        return 0;

    if (li == 1)
        return 1;

    ll op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

    op1 = 1 + TossCoins(li - 1, noteTaken, 1 + inBucket);

    if (inBucket != 0 && noteTaken < inBucket)
        op2 = 4 + TossCoins(li, inBucket, inBucket);

    if (li >= noteTaken && noteTaken != 0)
        op3 = 2 + TossCoins(li - noteTaken, noteTaken, inBucket + noteTaken);

    return dp[li][noteTaken] = min(op1, min(op2, op3));
}

int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    // for (int i = 0; i < 100003; i++)
    // {
    //     dp[i] = new int[100003];

    //     for(int j = 0 ; j < 100003 ; j++)
    //     dp[i][j] = -1;
    // }


    while (t--)
    {
        ll l;
        cin >> l;

        ll ans = 0;

        ans = TossCoins(l, 0, 0);
        cout << "Case #" << cnt << ": " << ans << "\n";
        cnt++;
    }
}