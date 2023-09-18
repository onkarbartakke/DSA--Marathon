#include <bits/stdc++.h>
#define ll long long
#define mod7 1000000007
using namespace std;

bool isPal(string &s)
{
    int i = 0, j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

ll factorial(ll n)
{
    ll ret = 1;

    for (ll i = 1; i <= n; i++)
        ret *= i;

    return ret;
}

ll solve(string s, unordered_map<string, ll> &mp)
{
    if (s.length() == 0)
        return 1;
    else if (s.length() == 1)
    {
        // cout<<"start\n";
        return 2;
    }

    // cout<<"1 here\n";

    if (mp.find(s) != mp.end())
        return mp[s];

    ll count = 0;
    if (isPal(s))
        count++;

    // cout<<"here\n";
    for (int i = 0; i < s.length(); i++)
    {
       // cout << s << "\n";
        string p = "";

        for (int j = 0; j < s.length(); j++)
        {
            if (i == j)
                continue;

            p.push_back(s[j]);
        }
        //cout << p << "\n";
        count += solve(p, mp);
    }

    mp[s] = count;

    return count;
}
pair<ll, ll> gcd_extend(ll a, ll b, ll MOD = mod7)
{
    if (b == 0)
    {
        return {1, 0};
    }
    else
    {
        pair<int, int> res = gcd_extend(b, a % b, MOD);
        ll q = a / b;
        return {res.second, (res.first - q * res.second) % MOD};
    }
}

ll invmod(ll n, ll p)
{
    // p is prime
    // or gcd(n,p) should be 1

    // it could grow too big cand couse overflow ??
    // may even become negative ?
    // using mod in the gcd_extend function ??

    pair<ll, ll> gcd_coeff = gcd_extend(n, p, p);
    int ans = gcd_coeff.first % p;
    if (ans < 0)
        ans += p;
    return ans;
}
int main()
{
    int t;
    cin >> t;

    int f = 1;

    while (t--)
    {
        int n;
        cin >> n;

        string s;

        cin >> s;

        unordered_map<string, ll> mp;

        ll Numrator = solve(s, mp);
        ll denominator = factorial(n);

        ll g = __gcd(Numrator,denominator);

        Numrator /= g;
        denominator /= g;
        
        ll E = ((Numrator)*invmod(denominator, mod7)) % mod7;
        cout << "Case #" << f << ": " << E << "\n";
        f++;
    }
}