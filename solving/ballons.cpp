#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool possible(ll mid, ll r, ll g, ll b)
{
    r -= mid;

    if (r >= mid)
    {
        r = 0;
    }
    else
    {
        ll rem = mid - r;
        b -= rem;
    }

    if (g + b < mid)
        return 0;
    else
        return 1;
}
int main()
{
    ll r, g, b;

    cin >> r >> g >> b; // a b c

    ll h = ((r + g + b) / 3) + 1, l = 0;

    if (g > r)
        swap(g, r);

    if (b > r)
        swap(b, r);

    if (b > g)
        swap(b, g);

    ll ans;
    while (l <= h)
    {
        ll mid = (l + h) / 2;

        if (possible(mid, r, g, b))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans << "\n";
}

/*

2 3 3
2 1 2
1 0 1

5 4 3

3 3 3
2 2 2
1 1 1
0 0 0
*/