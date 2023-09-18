#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    vector<pair<int,int>>times;

    for(int i = 0 ; i < n ; i++)
    {
        ll a,b;
        cin>>a>>b;

        times.push_back({a,0});
        times.push_back({b,1});
    }

    sort(times.begin() , times.end());

    int curr = 0 , ans = 0;
    int k = times.size();
    for(int i = 0 ; i < k ; i++)
    {
        //cout<<times[i].first<<" - "<<times[i].second<<"\n";
        if(times[i].second == 0)
        curr++;
        else if(times[i].second == 1)
        curr--;

        ans = max(ans,curr);
    }

    cout<<ans<<"\n";
}