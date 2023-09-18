#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> depth(100007);
vector<vector<int>> up(1000007, vector<int>(21, 1));
vector<int> In(100007, 0);
vector<int> Out(100007, 0);
vector<vector<int>> mp;
int n;
int timer = 0;
void DFS(int u, int par)
{
    In[u] = timer;
    timer++;

    for (auto v : mp[u])
    {
        if (v != par)
        {
            depth[v] = depth[u] + 1;
            up[v][0] = u;

            DFS(v, u);
        }
    }

    Out[u] = timer;
    timer++;
}

int getLCA(int a, int b)
{
    if (depth[b] > depth[a])
        swap(a, b);

    int k = depth[a] - depth[b];

    for (int i = 20; i >= 0; i--)
    {
        if (k && (1 << i))
        {
            a = up[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = 20; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

bool cmp(int a, int b)
{
    if (depth[a] >= depth[b])
        return true;
    else
        return false;
}

bool inPath(int n1, int n2, int lca, int n)
{
    if(n == lca)
    return true;


    if (In[n] >= In[lca] && In[n1] >= In[n] && Out[n1] <= Out[n] && Out[n] <= Out[lca])
        return true;

    if (In[n] >= In[lca] && In[n2] >= In[n] && Out[n2] <= Out[n] && Out[n] <= Out[lca])
        return true;

    return false;
}

bool isAncestor(int c, int a)
{
    if (In[a] <= In[c] && Out[c] <= Out[a])
        return true;
    else
        return false;
}

bool isSimplePath(vector<int> &nodes, int k)
{
    sort(nodes.begin(), nodes.end(), cmp);

    // for(auto it : nodes)
    // cout<<it<<" ";

    // cout<<"\n";

    int n1 = nodes[0];
    int n2 = -1;
    int lca;

    for (int i = 1; i < k; i++)
    {
        if (n1 != -1 && n2 != -1)
        {
            if (!inPath(n1, n2, lca, nodes[i]))
                return false;
        }
        else
        {
            if (!isAncestor(n1, nodes[i]))
            {
                //cout<<"\nFound n2 : "<<nodes[i]<<"\n";
                n2 = nodes[i];
                lca = getLCA(n1, n2);
            }
        }
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        mp = vector<vector<int>>(100007);
        cin >> n;

        int u, v;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int q;

        cin >> q;

        int k;

        depth[1] = 0;

        up[1][0] = 1;
        DFS(1, -1);

        for (int i = 1; i <= 20; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }

        while (q--)
        {
            cin >> k;

            vector<int> nodes(k);

            for (int i = 0; i < k; i++)
            {
                cin >> nodes[i];
            }

            if (isSimplePath(nodes, k))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}