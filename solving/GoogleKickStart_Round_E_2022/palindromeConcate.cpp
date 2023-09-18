#include <bits/stdc++.h>
#define ll long long

using namespace std;
// min chars to insert in beginning
bool palindrome(string a)
{
    int i = 0, j = a.length() - 1;

    while (i < j)
    {
        if (a[i] != a[j])
            return false;

        i++;
        j--;
    }

    return true;
}

bool palPartition(string &s, ll win)
{

    if (win == 1)
    {
        char c = s[0];

        for (char it : s)
        {
            if (c != it)
                return false;
        }

        return true;
    }
    ll n = s.length();

    if (n % win != 0)
        return false;

    int i = 0;
    string a = s.substr(0, win);

    if (!palindrome(a))
        return false;

    i = win;

    while (i < n)
    {
        string p = s.substr(i, win);

        if (p.compare(a) != 0)
            return false;

        i += win;
    }

    return true;
}
int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll low = 1, high = n, mid;

        ll ans = high;

        while (low <= high)
        {
            mid = (low) + (high - low) / 2;
            // cout<<"Mid : "<<mid<<"\n";
            if (palPartition(s, mid))
            {
                ans = mid;
                high = mid - 1;
                // cout<<"Inside if\n";
                // cout<<"ans : "<<ans<<"\n";
            }
            else
            {
                // cout<<"Inside else\n";
                low = mid + 1;
                // cout<<"low : "<<low<<"\n";
            }
        }

        string q = s.substr(0, ans);
        cout << "Case #" << cnt << ": " << q;
        cout << "\n";
        cnt++;
    }
}