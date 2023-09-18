#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        ll l,r;

        cin>>l>>r;

        if(l+3 == r)
        {
            ll curr = l;

            for(ll i = l + 1 ; i <= r ; i++)
            {
                curr = curr^i;
            }

            if(curr == 0)
            {
                cout<<l<<" "<<l+1<<" "<<l+2<<" "<<l+3<<"\n";
            }
            else
            {
                cout<<"-1\n";
            }
        }
        else
        {
            ll curr;
            if(l%2 == 0)
            curr = l;
            else
            curr = l+1;

            cout<<curr<<" "<<curr+1<<" "<<curr+2<<" "<<curr+3<<"\n";
           // cout<<(curr^(curr+1)^(curr+2)^(curr+3))<<"\n";
        }
    }
}