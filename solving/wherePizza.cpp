#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll pow2(ll len)
{
    if(len <= 32)
    {
        return (ll)(1<<len)%mod;
    }

    if(len&1)
    {
        ll newLen = (len-1)/2;
        ll ret = pow2(newLen);

        ll ans = ((ret%mod)*(ret%mod))%mod;
        return (2*ans)%mod;
    }
    else
    {
        
        ll newLen = (len)/2;
        ll ret = pow2(newLen);

        ll ans = ((ret%mod)*(ret%mod))%mod;
        return ans;
    }
}
int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;

        cin>>n;

        vector<int>a(n);
        vector<int>b(n);

        for(int i = 0 ; i < n ;i++)
        cin>>a[i];

        unordered_map<int,int>mp;

        ll ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            cin>>b[i];
            mp[b[i]] = i;
        }

        vector<int>c(n);
        unordered_set<int>st;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>c[i];

            if(c[i]>0)
            st.insert(c[i]);
        }

        //unordered_map<int,int>cyc;
        

        vector<bool>vis(n+1,false);

        for(int i = 0 ; i < n ; i++)
        {
            if(vis[b[i]])
            continue;
            
            bool include = true;

            vis[b[i]] = true;

            if(st.find(b[i])!=st.end())
            include = false;


            int u = a[i];
            int idx;
            int sz = 1;
            while(!vis[u])
            {
                if(st.find(u)!=st.end())
                {
                    include = false;
                }
               sz++;
               vis[u] = true;
               idx = mp[u];
               u = a[idx];

               if(!include)
               st.insert(u);

            }

            if(include && sz > 1)
            ans++;
            
        }

       
    
        ll ret = pow2(ans);

        //cout<<"Ans :  ";
        cout<<ret<<"\n";
    }
}
