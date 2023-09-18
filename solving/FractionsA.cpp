#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, c, d;

        cin >> a >> b >> c >> d;

        if (a % b == 0 && c % d == 0 && a / b == c / d)
        {
            cout << "0\n";
            continue;
        }

        if (a == 0 && c == 0)
        {
            cout << "0\n";
            continue;
        }
        else if (a == 0 || c == 0)
        {
            cout << "1\n";
            continue;
        }
        int g1 = __gcd(a, b);
        int g2 = __gcd(c, d);

        a = a / g1;
        b = b / g1;

        c = c / g2;
        d = d / g2;

        // int g = __gcd(a, c);

        // a = a / g;
        // c = c / g;

        // g = __gcd(b, d);
        // b = b / g;
        // c = c / g;

        long long n1 = c * b, d1 = a * d;

        if (a == c && b == d)
        {
            cout << "0\n";
            continue;
        }
        else if (a == c || b == d)
        {
            if (a != c)
            {
                int big = max(a, c);
                int small = min(a, c);

                if (big % small == 0)
                {
                    cout << "1\n";
                    continue;
                }
            }
            else if (b != d)
            {
                int big = max(b, d);
                int small = min(b, d);

                if (big % small == 0)
                {
                    cout << "1\n";
                    continue;
                }
            }
        }
        if (b != 0 && d != 0 && a % b == 0 && c % d == 0 && a / b == c / d)
            cout << "0\n";
        else if (a != 0 && c != 0 && b % a == 0 && d % c == 0 && b / a == d / c)
            cout << "0\n";
        else if (c * b == 1 && a * d == 1)
        {
            cout << "0\n";
        }
        else if (c * b == 1 || a * d == 1)
        {
            cout << "1\n";
        }
        else if ((d1 != 0 && n1 % d1 == 0) || (n1 != 0 && d1 % n1 == 0))
        {
            if (d1 != 0 && n1 % d1 == 0 && n1 / d1 == 1)
                cout << "0\n";
            else if (n1 != 0 && d1 % n1 == 0 && d1 / n1 == 1)
                cout << "0\n";
            else
                cout << "1\n";
        }
        else
            cout << "2\n";
    }
}
