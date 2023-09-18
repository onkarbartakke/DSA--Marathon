#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> mp;

    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }
}