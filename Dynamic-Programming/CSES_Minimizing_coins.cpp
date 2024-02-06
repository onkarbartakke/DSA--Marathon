#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,x;

    cin>>n>>x;

    vector<int>coins(n);

    for(int i = 0 ; i < n ; i++)
    cin>>coins[i];

    sort(coins.begin() , coins.end());
    vector<int>dp(x+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= x ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(coins[j] > i)
            break;
            else if(coins[j] == i)
            {
                dp[i] = 1;
                break;
            }
            else if(dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i] , 1 + dp[i - coins[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)
    cout<<-1;
    else
    cout<<dp[x];
}