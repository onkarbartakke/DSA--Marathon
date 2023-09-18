#include <bits/stdc++.h>
#define ll long long
//#define MOD 1000000007
using namespace std;

// unordered_map<int, vector<int>> mp;
// vector<int> values(200000 + 7);
// vector<int> In(200000 + 7);
// vector<int> Out(200000 + 7);

// vector<int> arr((200000 + 7) * 2, 0);
// vector<ll> seg((200000 + 7) * 4, 0);

//unordered_map<int, vector<int>> mp;

vector<vector<int>>mp(200007);
int values[200000 + 7];
int In[200000 + 7];
int Out[200007];

int arr[(200000 + 7) * 2];
ll seg[(200000 + 7) * 8];


int timer = 0;
// ifstream cin; // cin is like cin
// ofstream myfile;
void DFS(int u, int par)
{
    // cout << "\nInside Node : " << u << "\n";
    // myfile << "\nInside Node : " << u << "\n";

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

    arr[In[u]] = values[u];
    arr[Out[u]] = 0;
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
    ll n, q;

    // myfile.open("Output.txt");
    // cin.open("example.txt");
    cin >> n >> q;

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

   // cout << "Done with Input\n";

    // for (int i = 1; i <= n; i++)
    //     cout << values[i] << " ";

    cout << "\n\n";
    DFS(1, -1);
    //cout << "Done with DFS\n";
    int LOW = 0, HIGH = timer - 1;

    Build(0, LOW, HIGH);
    //cout << "Done with Build\n";
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
            // myfile << qa << "\n";
        }
    }
}