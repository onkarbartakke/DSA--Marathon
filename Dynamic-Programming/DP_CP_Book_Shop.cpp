#include<bits/stdc++.h>
#define ll long long

using namespace std;

//vector<vector<ll> >dp;

int dp[100003][1003];

ll solve(vector<int>&c , vector<int>&p , int ind, int moneyLeft)
{
    if(moneyLeft <= 0 || ind >= c.size())
    return 0;

    if(dp[moneyLeft][ind]!=-1)
    return dp[moneyLeft][ind];

    ll op1 = 0 , op2 = 0;

    if(moneyLeft >= c[ind])
    op1 = p[ind] + solve(c,p,ind+1,moneyLeft - c[ind]);

    op2 = solve(c,p,ind+1,moneyLeft);

    return dp[moneyLeft][ind] = max(op1,op2);
}


int main()
{
    int n,x;

    cin>>n>>x;

    //vector<int>cost(n) , pages(n);

    vector<vector<int> >mat(2, vector<int>(n));

    for(int i = 0 ; i < n ; i++)
    cin>>mat[0][i];

    for(int i = 0 ; i < n ; i++)
    cin>>mat[1][i];

   // sort(mat.begin() , mat.end());

    //vector<vector<int> > (x+1 , vector<int> (n+1, 0));
   // cout<<solve(cost,pages,0,x);
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout<<"Cost : "<<mat[0][i]<<" , Pages : "<<mat[1][i]<<"\n";
    // }


    dp[0][0] = 0;
   // memset(dp,0,sizeof(dp));


   for(int i = 0 ; i <= x ; i++)
   {
        for(int j = 0 ; j <= n ; j++)
        {   
            if(j == 0 || i == 0)
            dp[i][j] = 0;
            else if(i < mat[0][j-1])
            dp[i][j] = dp[i][j-1];
            else
            dp[i][j] = max(dp[i][j-1] , mat[1][j-1] + dp[i - mat[0][j-1]][j-1]);
        }
   }
   
   cout<<dp[x][n];
}