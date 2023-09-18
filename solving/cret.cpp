#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool static cmp(pair<int, string> &a, pair<int, string> &b)
{
    if (a.first == b.first)
    {
        string s1 = a.second;
        string s2 = b.second;

        int ret = s1.compare(s2);

        if (ret <= 0)
            return true;
        else
            return false;
    }
    else
        return a.first > b.first;
}

vector<vector<string>> mostPopularCreator(vector<string> &creat, vector<string> &ids, vector<int> &views)
{

    // unordered_map<string,string>mp;
    unordered_map<string, vector<pair<int, string>>> mp1;
    unordered_map<string, ll> sum;

    for (int i = 0; i < creat.size(); i++)
    {
        // mp[ids[i]] = creat[i];

        cout<<"Processing : "<<creat[i]<<"\n";
        mp1[creat[i]].push_back({views[i], ids[i]});

        sum[creat[i]] += (ll)views[i];
    }

    ll maxi = 0;

    for (auto it : sum)
    {
        cout<<maxi<<"\n";
        if (maxi < it.second)
            maxi = it.second;
    }

    vector<vector<string>> ans;

    for (auto it : sum)
    {
        if (it.second == maxi)
        {
            string cr = it.first;
            auto &v = mp1[cr];
            cout<<"For cr : "<<cr<<"\n";
           // sort(v.begin(), v.end(), cmp);

           ll idx, vs = -1;

            for(int i = 0 ; i < v.size() ; i++)
            {
                if(vs < v[i].first)
                {
                    vs = v[i].first;
                    idx = i;
                }
                else if(vs == v[i].first)
                {
                    if(v[i].second.compare(v[idx].second) < 0)
                    idx = i;
                }
            }

          

            ans.push_back({cr, v[idx].second});
        }
    }

    return ans;
}

int main()
{
    vector<string>cr;
    vector<string>id;
    vector<int>view;

    for(int i = 0 ; i < 100000 ; i++)
    {
        cr.push_back("a");
        id.push_back("a");
        view.push_back(100000);
    }

    auto ans = mostPopularCreator(cr,id,view);

    cout<<"\n\n";

    for(auto sv : ans)
    {
        for(auto s : sv)
        {
            cout<<s<<"  ";
        }

        cout<<"\n";
    }
}