#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>h(n);

    for(int i = 0 ; i < n ; i++)
    cin>>h[i];

    vector<ll>dp(n+1,INT_MAX);
    dp[0] = 0;

    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            if(i - j < 0)
            break;
            else if(dp[i-j]!=INT_MAX)
            {
                dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
    }

    cout<<dp[n-1];
}