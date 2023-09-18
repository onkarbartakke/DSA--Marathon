#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;

vector<int> S(3000), K(3000);
//unordered_map<int, vector<int>> mp;

vector<vector<int>>mp;
vector<vector<int>> dp(3000, vector<int>(3000, -1));

ll Traverse(int Kidx, int pos)
{
    if (pos >= n)
        return 0;

    if (S[pos] == S[pos - 1])
        return dp[pos][Kidx] = Traverse(Kidx, pos + 1);

    if (dp[pos][Kidx] != -1)
        return dp[pos][Kidx];


    auto v = mp[S[pos]];

    if(v.size() == 1)
        return dp[pos][Kidx] = abs(Kidx - v[0]) + Traverse(v[0] , pos+1);
    

    int idx = lower_bound(v.begin() , v.end() , Kidx) - v.begin();

    

    ll leftOption = INT_MAX, rightOption = INT_MAX;


    if(idx > 0)
    leftOption = abs(Kidx - v[idx-1]) + Traverse(v[idx-1],pos+1);

    if(idx < v.size())
    rightOption = abs(Kidx - v[idx]) + Traverse(v[idx],pos+1);

    return dp[pos][Kidx] = min(leftOption , rightOption);

}


ll getMinTime()
{
    ll ret = INT_MAX;

    auto v = mp[S[0]];

    for (auto i : v)
    {
        ret = min(ret, Traverse(i, 1));
    }

    return ret;
}


int main()
{
    int t;
    int count = 1;
    cin >> t;

    while (t--)
    {
        mp = vector<vector<int>>(3000);
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> S[i];

        cin >> m;

        for (int i = 0; i < m; i++)
        {
            cin >> K[i];

            mp[K[i]].push_back(i);
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
                dp[i][j] = -1;
        }
        ll timee = getMinTime();

        cout << "Case #" << count << ": " << timee << "\n";
        count++;

       // mp.clear();
    }
}