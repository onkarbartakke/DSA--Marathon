#include <bits/stdc++.h>

using namespace std;

/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element 
accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there 
is some common email to both accounts. Note that even if two accounts have the same name, they may belong 
to different people as people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account 
is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned 
in any order.

*/



class Solution
{

public:
    vector<int> parent;
    vector<int> rank;
    unordered_map<string, int> email_id;

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        else
            return parent[u] = findParent(parent[u]);
    }

    void MakeUnion(int u, int v)
    {
        if (rank[u] > rank[v])
            parent[v] = u;
        else if (rank[v] > rank[u])
            parent[u] = v;
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
      
      
        parent = vector<int>(accounts.size() + 1);
        rank = vector<int>(accounts.size() + 1, 0);

        for (int i = 0; i < accounts.size(); i++)
        {
            parent[i] = i;

            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (email_id.find(accounts[i][j]) != email_id.end())
                {
                    int f1 = findParent(i);
                    int f2 = findParent(email_id[accounts[i][j]]);

                    MakeUnion(f1, f2);
                }
                else
                    email_id[accounts[i][j]] = i;
            }
        }

        unordered_map<int, vector<string>> mres;

        for (auto it : email_id)
        {
            int id = findParent(it.second);
            mres[id].push_back(it.first);
        }

        vector<vector<string>> ans;

        for (auto it : mres)
        {
            vector<string> &v = it.second;
            sort(v.begin(), v.end());

            ans.push_back({accounts[it.first][0]});

            for (auto &s : v)
                ans.back().push_back(s);
        }

        return ans;
    }
};

int main()
{

}