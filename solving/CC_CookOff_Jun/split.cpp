#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        vector<ll>a(n);

        for(ll i = 0 ; i < n ; i++)
        {
            cin>>a[i];
        }

        ll cnt = 0, bit = 0;
        ll ansPow = -1 ,ansBit;
        ll p = 1;

        for(ll i = 0 ; i <= 30 ; i++)
        {
            cnt = 0;
            for(ll j = 0 ; j < n ; j++)
            {
                if(a[j]&p)cnt++;
            }

            if(cnt>=2)
            {
                ansPow = p;
                break;
            }

            p *=2;
            
        }

        if(ansPow == -1)
        cout<<"NO\n";
        else
        {
            vector<ll>v;

            for(ll i = 0 ; i < n ; i++)
            {
                if(a[i]&ansPow)
                {
                    v.push_back(i+1);
                }
            }

            cout<<"YES\n";
            cout<<v.size()<<"\n";

            cout<<"1 "<<v[1]-1<<"\n";

            for(ll i = 1 ; i < v.size() ; i++)
            {
                if(i == v.size() - 1)
                {
                    cout<<v[i]<<" "<<n<<"\n";
                }
                else
                {
                    cout<<v[i]<<" "<<v[i+1]-1<<"\n";
                }
            }
        }
    }
}