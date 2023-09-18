#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;

    cin >> t;
    int count = 1;
    while (t--)
    {
        int n, q;

        cin >> n >> q;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        vector<int> qus;

        for (int i = 0; i < q; i++)
        {
            int cnt;
            cin >> cnt;

            qus.push_back(cnt);
        }

        int ans = 0;

        int levels = 1;
        unordered_map<int, int> levelcnt;
        queue<int> qu;
        qu.push(1);

        vector<bool> vis(n + 1, false);
        vis[1] = true;


        while (!qu.empty())
        {
            int sz = qu.size();
            int childs = 0;
            while (sz--)
            {
                int u = qu.front();
                qu.pop();
                childs++;

                for (auto v : mp[u])
                {
                    if (!vis[v])
                    {
                        vis[v] = true;
                        qu.push(v);
                    }
                }
            }

            levelcnt[levels] = childs;
            levels++;
        }


        int lev = 1;

        while(q > 0)
        {
            if(q >= levelcnt[lev])
            {
                q -= levelcnt[lev];
                
                ans += levelcnt[lev];
                lev++;
            }
            else
            break;
        }


        cout << "Case #" << count << ": " << ans << "\n";
        count++;
    }
}