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

        double s2 = (n*(n+1));

        s2 = s2*y;

        s2 = (s2/(2*(x+y)));

        ll total_sum = (n*(n+1))/2;

        ll s2_int = (ll)s2;

        if(s2_int!=s2)
        {
            cout<<"Case #"<<f<<": "<<"IMPOSSIBLE\n";
        }
        else
        {
            ll alanSum = total_sum - s2_int;

            ll cur = n;
            vector<int>ans;


            while(alanSum > 0)
            {
                if(cur <= alanSum)
                {
                    ans.push_back(cur);
                    alanSum -= cur;
                }

                cur--;
            }

            cout<<"Case #"<<f<<": "<<"POSSIBLE\n";
            cout<<ans.size()<<"\n";

            for(int i = ans.size() - 1 ; i >= 0 ; i--)
            cout<<ans[i]<<" ";

            cout<<"\n";
        }

        f++;
    }
}