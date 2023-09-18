#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;

        int cost = 0;

        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++)
        {
            int oi;
            cin>>oi;

            mp[oi]++;
        }

        for(auto it : mp)
        {
            if(it.second >= c)
            cost += c;
            else
            cost += it.second;
        }

        cout<<cost<<"\n";
    }
}