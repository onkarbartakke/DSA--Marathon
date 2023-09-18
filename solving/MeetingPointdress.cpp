#include <bits/stdc++.h>
#define ll long long
#define err 0.000001
#define MAX 100000000
#define MIN 0

using namespace std;

double Compute(double m0, vector<double> &pos, vector<int> &times)
{
    int n = pos.size();

    double ans = 0.0;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (times[i] + abs(m0 - pos[i])));
    }

    return ans;
}

double TernarySearch(int n, vector<double> &pos, vector<int> &times, double high, double low)
{
    double m1, m2;
    double f1, f2;

    // double high, low;

    // high = pos[n - 1];
    // low = pos[0];

    while (abs(high - low) > err)
    {
        m1 = low + (high - low) / 3;

        m2 = high - (high - low) / 3;
        // cout<<"m1 : "<<m1<<"  m2 : "<<m2<<"\n";
        f1 = Compute(m1, pos, times);
        f2 = Compute(m2, pos, times);

        if (f1 < f2)
        {
            high = m2;
        }
        else
            low = m1;
    }

    return (low + high) / 2;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<double> pos(n);

        for (int i = 0; i < n; i++)
            cin >> pos[i];

        vector<int> times(n);

        for (int i = 0; i < n; i++)
            cin >> times[i];

        // sort(pos.begin(), pos.end());
        double h = pos[0], l = pos[0];

        for (int i = 0; i < n; i++)
        {
            if (h < pos[i])
                h = pos[i];

            if (l > pos[i])
                l = pos[i];
        }

        cout << setprecision(20) << fixed << TernarySearch(n, pos, times, h, l) << "\n";
    }
}