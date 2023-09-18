#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<int, int>> R;
        vector<int> rat(n);

        for (int i = 0; i < n; i++)
        {
            cin >> rat[i];

            R.push_back({rat[i], i});
        }

        sort(R.begin(), R.end());
        sort(rat.begin(), rat.end());

        vector<int> mentor(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            int j = upper_bound(rat.begin(), rat.end(), (2 * rat[i])) - rat.begin();

            if (j >= n)
                j = n - 1;

            while (j >= 0 && (rat[j] > 2 * rat[i] || R[i].second == R[j].second))
                j--;

            if (j >= 0 && rat[j] <= 2*rat[j])
                mentor[R[i].second] = rat[j];
        }

        cout << "Case #" << cnt << ": ";

        for (int i = 0; i < n; i++)
        {
            cout << mentor[i] << " ";
        }
        cout << "\n";
        cnt++;
    }
}