#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvlli;
typedef vector<vector<bool>> vvb;

#define endl "\n"
#define pb push_back
#define mod7 1000000007
#define mod9 1000000009
#define all(v) v.begin(), v.end()

#define trace1(x) \
    if (dm)       \
    cout << (#x) << " " << (x) << endl
#define trace2(x, y) \
    if (dm)          \
    cout << (#x) << " " << (x) << ", " << (#y) << " " << (y) << endl
#define trace3(x, y, z) \
    if (dm)             \
    cout << (#x) << " " << (x) << ", " << (#y) << " " << (y) << ", " << (#z) << " " << (z) << endl

#define min3(x, y, z) min(x, min(y, z))
#define max3(x, y, z) max(x, max(y, z))

template <typename T>
inline void sortv(vector<T> &vec)
{
    sort(vec.begin(), vec.end());
}
template <typename T>
inline void rsortv(vector<T> &vec) { sort(vec.begin(), vec.end(), greater<T>()); }
int dm = 0;
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
void fileio()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

int main()
{
#ifndef ONLINE_JUDGE
    dm = 1;
#endif
    fastio();
    fileio();

    int n;
    cin >> n;
    vvi adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // now take 1 as root and find height of all nodes
    // hieght of leaf is 1

    vi height_1(n + 1, -1);
    // height_1[i] is the hieght of node i when 1 is root
    // Will work in c++17 but not in C++11
    auto find_height_1 = [&](auto &&find_height_1, int cur, int par) -> int
    {
        // find height of node cur
        // assert(height_1[cur]==-1);
        if (adj[cur].size() == 0)
        {
            // possible when only one node is there in entire tree
            height_1[cur] = 1;
        }
        else if (adj[cur].size() == 1 && cur != 1)
        {
            // sure a leaf
            height_1[cur] = 1;
            // assert(adj[cur][0] == par);
        }
        else
        {
            // its non-leaf
            int h_child_max = 0;
            for (int v : adj[cur])
            {
                if (v != par)
                {
                    int h_child_cur = find_height_1(find_height_1, v, cur);
                    h_child_max = max(h_child_max, h_child_cur);
                }
            }

            height_1[cur] = h_child_max + 1;
        }

        return height_1[cur];
    };

    find_height_1(find_height_1, 1, -1);

    for (int i = 1; i <= n; i++)
        assert(height_1[i] != -1);

    vector<int> height_if_root(n + 1, -1);
    // height_if_root[i] is the height of tree with root as 'i'

    function<void(int, int, int)> find_height_if_root;

    find_height_if_root = [&](int cur, int parent, int parent_height) -> void
    {
        // find the max distance of cur
        // we have node cur, its parent
        // 'parent_height' is the height of tree with root as 'parent'
        // when we consider the all the childs of parent in the tree except cur.

        // we have hieght of all childs of 'cur'.
        // we can know the height of the tree if the tree with root as 'cur'

        // base cases...
        if (adj[cur].size() == 0)
        {
            // ultra special case
            height_if_root[cur] = 1;
            return;
        }
        else if (adj[cur].size() == 1)
        {
            if (parent == -1)
            {
                // main root
                // assert(cur==1);
                int child = adj[cur][0];
                find_height_if_root(child, cur, 1);

                // assert(height_1[cur] == height_if_root[child] + 1);

                height_if_root[cur] = height_1[cur];
            }
            else
            {
                // leaf (when root is 1)
                // assert(parent_height!=0);
                height_if_root[cur] = parent_height + 1;
            }

            return;
        }

        // adj.size()>=2

        int max_height_child = -1;
        int max_child_idx = -1;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int v = adj[cur][i];
            if (v != parent && height_1[v] > max_height_child)
            {
                // v is child of cur
                max_height_child = height_1[v];
                max_child_idx = i;
            }
        }

        height_if_root[cur] = max(parent_height + 1, max_height_child + 1);

        int second_max_height = -1;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int v = adj[cur][i];
            if (v != parent && i != max_child_idx && height_1[v] > second_max_height)
            {
                second_max_height = height_1[v];
            }
        }

        // what if second_max_height == -1

        // now find for childs
        int parent_height_new = 0;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int v = adj[cur][i];
            if (v != parent)
            {
                // assert(height_if_root[v]==-1);
                if (i == max_child_idx)
                {
                    if (second_max_height != -1)
                    {
                        parent_height_new = max(parent_height + 1, second_max_height + 1);
                    }
                    else
                    {
                        parent_height_new = parent_height + 1;
                    }
                }
                else
                {
                    parent_height_new = height_if_root[cur];
                }

                find_height_if_root(v, cur, parent_height_new);
            }
        }
    };

    find_height_if_root(1, -1, 0);

    for (int v = 1; v <= n; v++)
    {
        cout << height_if_root[v] - 1 << " ";
    }

    return 0;
}
