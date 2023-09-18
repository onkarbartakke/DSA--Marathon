#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n, x;

    cin >> n >> x;

    vector<ll> wt(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    sort(wt.begin(), wt.end());


    int i = 0 , j = n - 1;

    ll cnt = 0;

    while(i<=j)
    {
        if(i == j)
        {
            if(wt[i] <= x)
            cnt++;

            break;
        }

        if(wt[i]+wt[j] <= x)
        {
            i++;
            j--;

            cnt++;
        }
        else
        {
            j--;
            cnt++;
        }
    }

    cout<<cnt<<"\n";
}