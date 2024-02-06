#include<bits/stdc++.h>
#define ll long long

using namespace std;


int v1,v2,t,d,mx;
int dp[105][10005];


int solve(int i, int j)
{
    if(i == 1)
    {
        if(j == v1)
        return v1;
        else
        return INT_MIN;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];


    int ans = INT_MIN;


    for(int sp = j - d ; sp <= j + d ; sp++)
    {
        if(sp >= 0 && sp <= mx)
        {
            ans = max(ans, solve(i-1,sp));
        }
    }

    ans += j;

    return dp[i][j] = ans;
}
int main()
{
   
    cin>>v1>>v2;
    cin>>t>>d;
    mx = 10005;
    memset(dp,-1,sizeof(dp));

    cout<<solve(t,v2);
}