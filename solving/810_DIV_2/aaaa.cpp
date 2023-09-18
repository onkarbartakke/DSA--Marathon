#include <bits/stdc++.h>

using namespace std;

(string s)
{
    int n = s.length();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i <= n; i++)
        dp[i][i] = 1;

    for (int win = 2; win <= n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + win - 1;

            if (j >= n)
                break;

            if (win == 2 && s[i] == s[j])
                dp[i][j] = 2;
            else if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] =
        }
    }
}
int main()
{
}

int getPalindromeCount(string s)
{
    long ans = 0;
    int len = s.length();
    long[][] dp = new long[len][len];

    /* compute how many palindromes of length 3 are possible for every 2 characters match */
    for (int i = len - 2; i >= 0; --i)
    {
        for (int j = i + 2; j < len; ++j)
        {
            dp[i][j] = dp[i][j - 1] + (dp[i + 1][j] == dp[i + 1][j - 1] ? 0 : dp[i + 1][j] - dp[i + 1][j - 1]);
            if (s[i] == s[j])
            {
                dp[i][j] += j - i - 1;
            }
        }
    }

    /* re-use the above data to calculate for palindromes of length 5*/
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 4; j < len; ++j)
        {
            if (s[i] == s[j])
            {
                ans += dp[i + 1][j - 1];
            }
        }
    }

    // for(int i=0;i<len;++i) System.out.println(Arrays.toString(dp[i]));

    return ans;
}