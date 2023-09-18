#include <bits/stdc++.h>
#define ll long long
#define MSIZE 200007
using namespace std;

// unordered_map<int, vector<int>> mp;
vector<int> mp[200005];
vector<int> arr(2 * (MSIZE + 1));
vector<ll> seg(8*MSIZE);
vector<int> values(MSIZE, 0);
vector<int> In(MSIZE, 0);
vector<int> Out(MSIZE, 0);
int timer = 0;

ifstream input;
ofstream output;

void DFS(int u, int par)
{
  //  cout << "Inside Node : " << u << "\n";
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
    arr[Out[u]] = -values[u];
}

void Build(int ind, int low, int high)
{
    // cout<<"Low : "<<low<<" High : "<<high<<"\n";
    if (low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low) + (high - low) / 2;

    Build(2 * ind + 1, low, mid);
    Build(2 * ind + 2, mid + 1, high);

    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}

void Update(int ind, int i, int val, int low, int high)
{
    if (low == high)
    {
        seg[ind] = val;
        return;
    }

    int mid = (low) + (high - low) / 2;

    if (i <= mid)
        Update(2 * ind + 1, i, val, low, mid);
    else
        Update(2 * ind + 2, i, val, mid + 1, high);

    seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
}

ll Query(int ind, int left, int right, int low, int high)
{
    if (right < low || high < left)
        return 0;

    if (left <= low && high <= right)
        return seg[ind];

    int mid = low + (high - low) / 2;

    ll leftSide = Query(2 * ind + 1, left, right, low, mid);
    ll rightSide = Query(2 * ind + 2, left, right, mid + 1, high);

    return leftSide + rightSide;
}
int main()
{
    ll n, q;
    // input.open("pathqueryInput.txt");
    // output.open("output.txt");
    // output << "Writing \n";
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> values[i];

    // for (int i = 1; i <= n; i++)
    //     cout << values[i] << "  ";

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        // cout<<"HI"<<endl;
        cin >> a >> b;

        mp[a].push_back(b);
        mp[b].push_back(a);
    }

  
    DFS(1, -1);
    int LOW = 0, HIGH = timer - 1;
   
    Build(0, LOW, HIGH);
 
    while (q--)
    {
        int t;

        cin >> t;

        if (t == 1)
        {
            int s, x;
            cin >> s >> x;

            Update(0, In[s], x, LOW, HIGH);
            Update(0, Out[s], -x, LOW, HIGH);
        }
        else
        {
            int s;
            cin >> s;

            int left = 0;
            int right = In[s];

            cout << Query(0, left, right, LOW, HIGH) << "\n";
        }
    }
}