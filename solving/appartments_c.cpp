#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    long long n,m,k;

    cin>>n>>m>>k;

    vector<ll>app(n) , req(m);

    for(int i = 0 ; i < n ; i++)
    {
        cin>>app[i];
    }

    for(int i = 0 ; i < m ; i++)
    {
        cin>>req[i];
    }


    sort(app.begin() , app.end());
    sort(req.begin() , req.end());

    ll i = 0 , j = 0 , cnt = 0;

    while(i<n && j < m)
    {
        if(abs(app[i] - req[j]) <= k)
        {
            i++;
            j++;
            cnt++;
        }
        else if(app[i] < req[j])
        i++;
        else if(req[j] < app[i])
        j++;
    }

    cout<<cnt<<"\n";
}