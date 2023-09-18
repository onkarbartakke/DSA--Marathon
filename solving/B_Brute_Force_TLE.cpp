// Author : Nitin Kumar

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vlli;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();

    int n, q;
    cin >> n >> q;

    vi x(n);
    for (int &i : x)
        cin >> i;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        lli ans = 0;
        for (int i = a; i <= b; i++)
        {
            ans += x[i];
        }

        cout << ans << " ";
    }

    return 0;
}
