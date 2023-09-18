#include <bits/stdc++.h>
#define ll long long

using namespace std;

int circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (d <= r1 - r2)
    {
        return 0;
    }
    else if (d <= r2 - r1)
    {
        return 0;
    }
    else if (d < r1 + r2)
    {
        return 0;
    }
    else if (d == r1 + r2)
    {
        return 0;
    }
    else
    {
        return 1; 
    }
}

int main()
{
    
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {

        int rs, rh;

        cin >> rs >> rh;

        int n, m;

        cin >> n;

        vector<pair<int, int>> red;
        int x, y;

        set<pair<double, int>> st;

        double dist = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;

            red.push_back({x, y});

            int ci = circle(x, y, 0, 0, rs, rh);

            if (ci == 0)
            {
                dist = sqrt((double)(x * x + y * y));
                st.insert({dist, 0});
            }
        }

        cin >> m;

        vector<pair<int, int>> yellow;

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            yellow.push_back({x, y});

            int ci = circle(x, y, 0, 0, rs, rh);

            if (ci == 0)
            {
                dist = sqrt((double)(x * x + y * y));
                st.insert({dist, 1});
            }
        }

        int r = 0;
        y = 0;
        
        auto k = st.begin();

        int team;
        if (!st.empty())
        {

            team = (*k).second;

            for (auto it : st)
            {
                if (it.second != team)
                    break;

                if (it.second == 0)
                    r++;
                else
                    y++;
            }
        }

        cout << "Case #" << cnt << ": " << r << " " << y << "\n";
        cnt++;
    }
}