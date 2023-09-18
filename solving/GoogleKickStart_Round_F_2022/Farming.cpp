#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;

    cin >> t;
    int count = 1;
    while (t--)
    {
        ll ans = 0;

        ll d, n, x;

        cin >> d >> n >> x;

        ll total_seeds = d * x;

        vector<vector<ll>> seeds;

        priority_queue<vector<ll>, vector<vector<ll>>> pq;

        for (int i = 0; i < n; i++)
        {
            ll q, l, v;

            cin >> q >> l >> v;

            seeds.push_back({v, l, q});
            pq.push({v, l, q});
        }

        // sort(seeds.begin(), seeds.end());

        vector<ll> days(d, 0);

        for (int i = 0; i < n; i++)
        {
            if (pq.empty())
                break;

            auto p = pq.top();
            pq.pop();

            ll maxDay = (d - p[1] - 1);

            while (maxDay >= 0 && p[2] > 0)
            {
                if (days[maxDay] < x)
                {
                    ll sds = min(x - days[maxDay], p[2]);

                    p[2] -= sds;
                    days[maxDay] += sds;

                    ans += (sds * p[0]);
                }

                if (days[maxDay] == x)
                    maxDay--;
            }

            if (p[2] > 0)
                pq.push(p);
        }

        cout << "Case #" << count << ": " << ans << "\n";
        count++;
    }
}
