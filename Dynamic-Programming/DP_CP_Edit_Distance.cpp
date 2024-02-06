#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    string s1,s2;

    cin>>s1;
    cin>>s2;

    int n = s1.length() , m = s2.length();

    vector<vector<ll> > dp(n+1 , vector<ll> (m+1 , 0));

    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= m ; j++)
        {
            if(i == 0)
            dp[i][j] = j;
            else if(j == 0)
            dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            {
                ll op1 = dp[i-1][j];

                ll op2 = dp[i][j-1];

                ll op3 = dp[i-1][j-1];

                dp[i][j] = 1 + min(op1, min(op2,op3));
            }
        }
    }

    cout<<dp[n][m];
}