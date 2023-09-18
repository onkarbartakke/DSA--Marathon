#include <bits/stdc++.h>
#define ll long long
#define MAX_N 200007

using namespace std;

int n, m;
vector<vector<int>> mp(MAX_N);
vector<bool> vis(MAX_N, false);
bool isCycle = false;
vector<bool> Instack(MAX_N, false);
vector<int> ans;
stack<int> st;

void DFS(int u)
{
    Instack[u] = true;
    vis[u] = true;
    st.push(u);

    for (auto v : mp[u])
    {
        if (Instack[v])
        {
            isCycle = true;

            ans.push_back(v);
            while (!st.empty() && st.top() != v)
            {
                ans.push_back(st.top());
                st.pop();
            }

            ans.push_back(v);

            reverse(ans.begin(), ans.end());

            return;
        }

        if (!vis[v])
            DFS(v);

        if (isCycle)
            return;
    }

    Instack[u] = false;

    if(!st.empty())
    st.pop();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        mp[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            DFS(i);

        if (isCycle)
            break;
    }

    if (isCycle)
    {
        cout<<ans.size()<<"\n";
        for (auto it : ans)
            cout << it << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}