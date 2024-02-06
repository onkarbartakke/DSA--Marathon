#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[501][501];


// ll solve(int ind, vector<int>&cord, vector<int>&limit, int k, int curSpeed, int l)
// {
//     if(ind >= cord.size())
//     {
//        int dist = l - cord[cord.size()-1];
//        int time = dist*curSpeed;
//        return time;
//     }

//     if(dp[ind][k]!=-1)
//     return dp[ind][k];


//     int op1 = INT_MAX, op2 = INT_MAX;

//     int curTime = curSpeed*(cord[ind] - cord[ind-1]);


//     if(k > 0)
//     op1 = solve(ind+1,cord,limit,k-1,curSpeed,l);

//     op2 = solve(ind+1,cord,limit,k,limit[ind],l);

//     return  dp[ind][k] = curTime + min(op1,op2);
// }

int solve(int left, int pos)
{
    
}

int main()
{
    int n,l,k;
    cin>>n>>l>>k;

    vector<int>cord(n+1),limit(n+1);

    for(int i = 0 ; i < n ; i++)
    cin>>cord[i];

    for(int i = 0 ; i < n ; i++)
    cin>>limit[i];

    cord[n] = l;
    limit[n] = 0;

    memset(dp,-1,sizeof(dp));
    int ans = INT_MAX;

    for(int i = 0 ; i <= k ; i++)
    {
        ans = min(ans, solve(i,n+1));
    }

    cout<<ans;
}