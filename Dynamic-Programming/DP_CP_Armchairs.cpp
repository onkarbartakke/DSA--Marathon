#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>filled, not_filled;

    int x;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>x;
        if(x)
        filled.push_back(i);
        else
        not_filled.push_back(i);
    }

    int n1 = filled.size() , n2 = not_filled.size();

    vector<vector<ll> >dp(n1+3, vector<ll>(n2+5, INT_MAX));

    dp[0][0] = 0;

    for(int i = 0 ; i <= n1 ; i++)
    {
       for(int j = 0 ; j <= n2 ; j++)
       {
            if(i > 0 && j > 0)
            {
                dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + abs(filled[i-1] - not_filled[j-1]));
            }

            if(j>0)
            dp[i][j] = min(dp[i][j] , dp[i][j-1]);
       }
    }

    cout<<dp[n1][n2]<<"\n";
}