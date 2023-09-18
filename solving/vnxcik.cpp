#include <bits/stdc++.h>

using namespace std;

#define ll long long
class Solution
{
public:
    vector<int> k_Transformation(int n, int m, int k, vector<vector<int>> grid, int q, vector<vector<int>> queries)
    {
        // code here

        vector<int> ans;

        for (int i = 0; i < q; i++)
        {
            auto &v = queries[i];

            int t = v[0];
            int val = v[1];
            int nv;
            for (int ki = 0; ki < k; ki++)
            {
                ll newVal = ki;

                newVal = (newVal + t) % k;

                if (newVal == val)
                {
                    nv = ki;
                    break;
                }
            }

            int cnt = 0;
            for (int p = v[2]; p <= v[4]; p++)
            {
                for (int qj = v[3]; qj <= v[5]; qj++)
                {
                    if (nv == grid[p][qj])
                        cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};

