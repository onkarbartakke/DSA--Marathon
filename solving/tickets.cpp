#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m;

    cin >> n >> m;

    vector<ll> tick(n), cap(m);

    for (int i = 0; i < n; i++)
        cin >> tick[i];

    for (int i = 0; i < m; i++)
        cin >> cap[i];

    sort(tick.begin(), tick.end());
    //sort(cap.begin(), cap.end());

    vector<bool>vis(n,true);

    for(int i = 0 ; i < m ; i++)
    {
        int j = upper_bound(tick.begin() , tick.end() , cap[i]) - tick.begin();

        if(j> n)
        j = n - 1;

        
        while(j>=0 && (vis[j] == false || cap[i] < tick[j]))
        j--;

        if(j>=0 && vis[j])
        {
            vis[j] = false;
            cout<<tick[j]<<"\n";
        }
        else
        cout<<"-1\n";
    }
}