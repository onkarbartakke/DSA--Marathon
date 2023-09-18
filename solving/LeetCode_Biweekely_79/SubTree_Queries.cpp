#include <bits/stdc++.h>
#define ll long long
//#define MOD 1000000007
using namespace std;

#define trace(x) cout << #x << " = " << x << endl
int dm = 0;

vector<vector<int>> mp(200007);
int values[200000 + 7];
int In[200000 + 7];
int Out[200007];

int arr[(200000 + 7) * 2];
ll seg[(200000 + 7) * 8];

int timer = 0;
ifstream indata;
ofstream myfile;

int n, q;

vector<bool> visited;

ll ndfs = 0;

void DFS(int u, int par)
{

    ndfs++;

    if (dm && ndfs % 1000 == 10000)
    {
        cout << "\nInside Node : " << u << "\n";
        trace(timer);
        trace(ndfs);
        trace(par);
    }

    assert(ndfs <= n);

    assert(u >= 1 && u <= n && par <= n);

    assert(!visited[u]);

    visited[u] = true;

    In[u] = timer;
    timer++;

    for (auto child : mp[u])
    {
        if (child != par)
        {
            DFS(child, u);
        }
    }

    Out[u] = timer;
    timer++;

    assert(In[u] <= 2 * n);
    assert(Out[u] <= 2 * n);

    arr[In[u]] = values[u];
    arr[Out[u]] = 0;

    if (dm && ndfs % 10 == 0)
    {
        cout << "\nGoing out of Node : " << u << "\n";
        
    }
}

void Build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    ll mid = (high - low) / 2 + low;

    Build(2 * ind + 1, low, mid);
    Build(2 * ind + 2, mid + 1, high);

    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}

void Update(ll ind, ll i, ll val, ll low, ll high)
{
    if (low == high)
    {
        seg[ind] = val;
        return;
    }

    ll mid = low + (high - low) / 2;

    if (i <= mid)
        Update(2 * ind + 1, i, val, low, mid);
    else
        Update(2 * ind + 2, i, val, mid + 1, high);

    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}

ll Query(ll ind, ll left, ll right, ll low, ll high)
{
    if (right < low || high < left)
        return 0;

    if (low >= left && high <= right)
        return seg[ind];

    ll mid = low + (high - low) / 2;

    ll LeftSide = Query(2 * ind + 1, left, right, low, mid);
    ll RightSide = Query(2 * ind + 2, left, right, mid + 1, high);

    return (LeftSide + RightSide);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("example.txt", "r", stdin);
    dm = 1;
#endif

    cin >> n >> q;

    visited = vector<bool>(n + 1, false);

    for (ll i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;

        cin >> a >> b;

        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    if (dm)
        cout << "Done with Input\n";

    DFS(1, -1);
    if (dm)
        cout << "Done with DFS\n";
    int LOW = 0, HIGH = timer - 1;

    Build(0, LOW, HIGH);
    if (dm)
        cout << "Done with Build\n";
    while (q--)
    {
        ll t, val, node;

        cin >> t;

        if (t == 1)
        {
            cin >> node >> val;
            Update(0, In[node], val, LOW, HIGH);
            values[node] = val;
            arr[In[node]] = val;
        }
        else
        {
            cin >> node;

            ll left = In[node];
            ll right = Out[node];

            ll qa = Query(0, left, right, LOW, HIGH);
            cout << qa << "\n";
        }
    }
}