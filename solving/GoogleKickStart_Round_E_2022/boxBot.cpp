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
        int n;
        cin >> n;

        int ans = 1;

        int B = 1, J = 4;

        while (B <= n)
        {
            if (J + 2 <= n)
            {
                B = J + 2;
                ans++;

                J = B + 3;
            }
            else
                break;
        }

        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}