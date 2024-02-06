#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k,z;

        cin>>n>>k>>z;

        vector<int>arr(n) , sum(n,0);

        for(int i = 0 ; i < n ; i++)
        cin>>arr[i];

        sum[0] = arr[0];

        for(int i = 1 ; i < n ; i++)
        sum[i] = sum[i-1] + arr[i];

        ll ans = sum[k];

        for(int i = 0 ; i < k ; i++)
        {
            for(int j = 1 ; j <= z ; j++)
            {
                int r = k - 2*j;

                if(r >= i)
                {
                    ans = max(ans, (ll)sum[r] + j*(arr[i] + arr[i+1]));
                }
            }
        }

        cout<<ans<<"\n";
    }
}