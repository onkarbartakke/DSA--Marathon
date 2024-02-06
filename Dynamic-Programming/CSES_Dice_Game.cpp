#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<ll>dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1 ; j <= 6 ; j++)
        {
            if(i - j >= 0)
            dp[i] += dp[i - j], dp[i] %= MOD;
        }
    }

    cout<<dp[n];
}