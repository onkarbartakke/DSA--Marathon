#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;

    cin>>t;
    int f = 1;

    while(t--)
    {
        ll n,x,y;

        cin>>n>>x>>y;

        ll total_sum = (n*(n+1))/2;

        vector<vector<bool>>dp(n+1,vector<bool>(total_sum+1,false));
        vector<int>ans;
        dp[0][0] = true;
        bool possible = false;


        for(ll i = 0 ; i <=n ; i++)
        {
            for(ll j = 0 ; j <=total_sum ; j++)
            {
                //cout<<"i :  "<<i<<"  j : "<<j<<"\n";
                if(j == 0)
                dp[i][j] = true;
                else if( i == 0)
                dp[i][j] = false;
                else if(j >= i)
                {
                    //cout<<"i : "<<i<<" j : "<<j<<" dps : "<<dp[i-1][j]<<"  ,  "<<dp[i-1][j-1]<<"\n";
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-i]);
                }
                else
                dp[i][j] = dp[i-1][j];

                if(dp[i][j] == true && j!=0)
                {
                    ll SX = j;
                    ll SY = total_sum - SX;

                    ll gcd = __gcd(SX,SY);

                    SX /= gcd;
                    SY /= gcd;

                    if(SX == x && SY == y)
                    {
                        possible = true;
                        int p,q;
                        p = i;
                        q = j;

                        while(p > 0)
                        {
                            if(dp[p-1][q] == true)
                            p--;
                            else
                            {
                                ans.push_back(p);
                                q =  q - p;
                                p--;
                            }
                        }

                        break;
                    }
                    
                }

               
            }

            if(possible)
            break;
        }

        // for(int i = 0 ; i <= n ; i++)
        // {
        //     for(int j = 0 ; j <= total_sum ; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }

        //     cout<<"\n";
        // }
        if(possible)
        {
            cout<<"Case #"<<f<<": "<<"POSSIBLE\n";
            cout<<ans.size()<<"\n";
            for(int i = ans.size()-1 ; i>=0 ; i--)
            cout<<ans[i]<<" ";

            cout<<"\n";
        }
        else
        cout<<"Case #"<<f<<": "<<"IMPOSSIBLE\n";

        f++;
    }
}