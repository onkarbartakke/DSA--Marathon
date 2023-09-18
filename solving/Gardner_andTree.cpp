#include<bits/stdc++.h>
#define ll long long
using namespace std;




int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;


        cin>>n>>k;

        unordered_map<int, vector<int>>mp;

        int u,v;

        vector<int>rem(n+1,0) , layer(n+1,0);


        for(int i = 0 ; i < n - 1 ; i++)
        {
            cin>>u>>v;

            mp[u].push_back(v);
            mp[v].push_back(u);

            rem[u]++;
            rem[v]++;
        }

        queue<int>qu;

        for(int i = 1 ; i <= n ; i++)
        {
            if(rem[i] == 1)
            {
                qu.push(i);
                layer[i] = 1;
            }
        }


        while(!qu.empty())
        {
            int u = qu.front();
            qu.pop();

            for(auto v : mp[u])
            {
                if(rem[v]!=1)
                {
                    rem[v]--;

                    if(rem[v] == 1)
                    {
                        qu.push(v);
                        layer[v] = layer[u] + 1;
                    }
                }
            }
        }


        int ans = 0;

        for(int i = 1;  i <= n ; i++)
        {
            if(layer[i] > k)
            ans++;
        }

        cout<<ans<<"\n";
    }
}





// Correct approach but gives TLE
int main1_()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;

        cin>>n>>k;

        if(n == 1 && k>0)
        {
            cout<<"0\n";
            continue;
        }
        map<int, set<int>>mp;

        for(int i = 0 ; i < n - 1 ;i++)
        {
            int u,v;
            cin>>u>>v;

            mp[u].insert(v);
            mp[v].insert(u);
        }

        int ans = n;

        //cout<<"Here\n";



        while(k--)
        {
            set<int>st;

            for(auto it : mp)
            {
               if(it.second.size() <= 1)
               {
                 st.insert(it.first);
               }
            }


            for(auto u : st)
            {
                int v = (*mp[u].begin());

                //cout<<"Leaf node is : "<<u<<"\n";
               // cout<<"\nNew leaf node will be : "<<v<<"\n";

                mp[v].erase(u);
                mp.erase(u);

                ans--;

                if(ans == 0)
                break;
            }

            if(ans == 0)
            break;
        }


        cout<<ans<<"\n";



    }
}