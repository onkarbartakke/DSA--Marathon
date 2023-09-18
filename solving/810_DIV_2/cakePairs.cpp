#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;

        cin>>n>>m;

        vector<int>arr(n+1);

        for(int i = 1 ; i <= n ; i++)
        cin>>arr[i];

        priority_queue<pair<int, pair<int,int> > , vector<pair<int, pair<int,int> >> >pq;

        vector<pair<int,int>>vp;
        ll ans = 0;
        for(int i = 0 ; i < m ; i++)
        {
            int a,b;
            cin>>a>>b;

            vp.push_back({a,b});

            pq.push({arr[a]+arr[b], {a,b}});
        }

        for(auto it : arr)
        ans += it;

        vector<bool>vis(n+1,false);


        while(pq.size() > 1)
        {
            auto p = pq.top();
            pq.pop();

            int f1 = p.second.first;
            int f2 = p.second.second;

            if(!vis[f1] && !vis[f2])
            {
                vis[f1] = true;
                vis[f2] = true;

                ans -= p.first;
            }

            p = pq.top();
            pq.pop();

            f1 = p.second.first;
            f2 = p.second.second;

            if(!vis[f1] && !vis[f2])
            {
                vis[f1] = true;
                vis[f2] = true;

                ans -= p.first;
            }
        }


        int f1 = -1 , f2 = -1;

        if(pq.size() == 1)
        {
            auto p = pq.top();
            f1 = p.second.first;
            f2 = p.second.second;
        }

        for(int i = 1 ; i <= n ; i++)
        {
            if(!vis[i] && i!=f1 && i!=f2)
            {
                vis[i] = true;
                ans -= arr[i];
            }
        }

        if(pq.size() == 1)
        {
            if(arr[f1] > arr[f2])
            ans -= arr[f1];
            else
            ans -= arr[f2];
        }


        cout<<ans<<"\n";
        
    }
}