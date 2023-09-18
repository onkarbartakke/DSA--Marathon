#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int n;

int maxSize = (1 << 21) - 1;

vector<vector<int>> dp(22, vector<int>(maxSize + 1, -1));
vector<vector<int>> mat(22, vector<int>(22));

int solve(int i, int mask)
{
   // cout<<i<<"\n";
    if (i == n)
        return 1;


    if (dp[i][mask] != -1)
        return dp[i][mask];
    
    ll total = 0;

    for(int j = 0 ; j < n ; j++)
    {
        if(mat[i][j] == 1 && (mask & (1<<j)) == 0)
        {
            total = (total + solve(i+1, (mask | (1<<j))))%MOD;
        }
    }    

    dp[i][mask] = (int)(total%MOD);

    return dp[i][mask];
}


int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    cout<< solve(0, 0);
}