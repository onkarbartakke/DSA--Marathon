#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;

        cin >> n;

        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<ll> dmin(n), dmax(n);

        list<ll>ls;
        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

            dmin[i] = b[j] - a[i];

            dmax[i] = b[i] - a[i];
        }

        for (auto it : dmin)
            cout << it << " ";

        cout << "\n";

        for (auto it : dmax)
            cout << it << " ";

        cout << "\n";
    }
}