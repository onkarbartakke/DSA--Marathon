#include<bits/stdc++.h>

using namespace std;

int sumMax(vector<vector<int>>&a)
{
     int n = a.size() , m = a[0].size();

     vector<vector<int>>dp(n, vector<int>(m));

     for(int  i = 0 ; i < n ; i ++)
     {
        for(int j = 0 ; j < m ; j ++)
        {
            if(i == 0 && j == 0)
            dp[i][j] = a[i][j];
            else if(i == 0)
            dp[i][j] = a[i][j] + dp[i][j-1];
            else if(j == 0)
            dp[i][j] = a[i][j] + dp[i-1][j];
            else
            {
                dp[i][j] = a[i][j] + max(dp[i][j-1] , dp[i-1][j]);
            }

        }
     }

     return dp[n-1][m-1];
}


int sumMin(vector<vector<int>>&a)
{
     int n = a.size() , m = a[0].size();

     vector<vector<int>>dp(n, vector<int>(m));

     for(int  i = 0 ; i < n ; i ++)
     {
        for(int j = 0 ; j < m ; j ++)
        {
            if(i == 0 && j == 0)
            dp[i][j] = a[i][j];
            else if(i == 0)
            dp[i][j] = a[i][j] + dp[i][j-1];
            else if(j == 0)
            dp[i][j] = a[i][j] + dp[i-1][j];
            else
            {
                dp[i][j] = a[i][j] + min(dp[i][j-1] , dp[i-1][j]);
            }

        }
     }

     return dp[n-1][m-1];
}
int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,m;

        cin>>n>>m;

       vector<vector<int>>a(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            cin>>a[i][j];
        }


        if((n+m-1)%2 == 1)
        cout<<"NO\n";
        else
        {
            if(sumMax(a) < 0 || sumMin(a) > 0)
            cout<<"NO\n";
            else
            cout<<"YES\n";
        }

    }

}

