#include <bits/stdc++.h>
#define ll long long
#define LOG 21
#define MAX_N 200007
using namespace std;

vector<int> depth(MAX_N, 0);

vector<vector<int>> up(MAX_N, vector<int>(LOG, 0));
int n, q;

vector<vector<int>> mp(MAX_N);

void DFS(int u, int p)
{
    //cout << "Inside Node : " << u << "\n";
    for (auto child : mp[u])
    {
        if (child != p)
        {
            depth[child] = depth[u] + 1;

            up[child][0] = u;

            // for (int i = 1; i < LOG; i++)
            // {
            //     if((1<<i) > depth[child] )
            //     break;

            //     up[child][i] = up[up[child][i - 1]][i - 1];
            // }

            DFS(child, u);
        }
    }
}

int getLCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int k = depth[a] - depth[b];

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;

        cin >> u >> v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    depth[1] = 0;

    DFS(1, -1);

    for(int i = 1 ; i < LOG ; i++)
    {
        for(int j = 2 ; j<=n ; j++)
        {
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }

    //cout<<"Depths are : \n";

    // for(int i = 1 ; i <= n ; i++)
    // {
    //     cout<<i<<" : "<<depth[i]<<"\n";
    // }

    while (q--)
    {
        int a, b;

        cin >> a >> b;

        int u = getLCA(a, b);

        // cout<<"Depth of "<<a<<" : "<<depth[a]<<"\n";

        // cout<<"Depth of "<<b<<" : "<<depth[b]<<"\n";

        // cout<<"LCA of a and b = "<<u<<"\n";

        // cout<<"Depth of LCA "<<u<<" : "<<depth[u]<<"\n";

        cout << (depth[a] + depth[b] - 2 * depth[u]) << "\n";
    }
}

