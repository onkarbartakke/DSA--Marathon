#include <bits/stdc++.h>
#define ll long long

using namespace std;
char dir[5] = {'N', 'E', 'W', 'S', '\0'};
bool comp = false;
void DFS(int r, int c, vector<vector<int>> &mat, unordered_map<char, pair<char, int>> &mp, int time, int currPizza, int m, ll val, ll &ans, int p, vector<vector<int>> &vis)
{
    if (time > m)
        return;
    int n = mat.size() - 1;

    if (r <= 0 || c <= 0 || r > n || c > n)
        return;

    if (vis[r][c] == 0 && mat[r][c]!=0)
    {
        val += mat[r][c];
        currPizza++;
    }

    vis[r][c]++;

    if (time == m)
    {
        if (currPizza == p)
        {
            ans = max(ans, val);
            comp = true;
        }
        vis[r][c]--;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        char op = mp[dir[i]].first;
        int k = mp[dir[i]].second;

        ll newVal;

        if (op == '+')
            newVal = val + k;
        else if (op == '-')
            newVal = val - k;
        else if (op == '*')
            newVal = val * k;
        else
            newVal = val / k;

        if (i == 0)
            DFS(r - 1, c, mat, mp, time + 1, currPizza, m, newVal, ans, p, vis);
        else if (i == 1)
            DFS(r, c + 1, mat, mp, time + 1, currPizza, m, newVal, ans, p, vis);
        else if (i == 2)
            DFS(r, c - 1, mat, mp, time + 1, currPizza, m, newVal, ans, p, vis);
        else if (i == 3)
            DFS(r + 1, c, mat, mp, time + 1, currPizza, m, newVal, ans, p, vis);
    }

    vis[r][c]--;
    return;
}
int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        int n, m, p;
        cin >> n >> p >> m;

        int ar, ac;
        cin >> ar >> ac;

        unordered_map<char, pair<char, int>> mp;

        for (int i = 0; i < 4; i++)
        {
            char op;
            int k;

            cin >> op >> k;

            mp[dir[i]].first = op;
            mp[dir[i]].second = k;
        }

        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < p; i++)
        {
            int r, c, coin;
            cin >> r >> c >> coin;

            mat[r][c] = coin;
        }

        ll ans = 0;
        vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));

        DFS(ar, ac, mat, mp, 0, 0, m, 0, ans, p, vis);

        if (comp && ans > 0)
            cout << "Case #" << cnt << ": " << ans;
        else
            cout << "Case #" << cnt << ": IMPOSSIBLE";
        cout << "\n";
        cnt++;
    }
}