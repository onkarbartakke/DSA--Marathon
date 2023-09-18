#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(vector<int> &laddoos, int n, vector<pair<int, int>> &queries, int k)
{
    vector<long long int> prefix(n);

    prefix[0] = laddoos[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + laddoos[i];
    }

    for (int i = 0; i < k; i++)
    {

        int left = queries[i].first;
        int right = queries[i].second;

        left -= 1;
        right -= 1;

        if (left == 0)
        {
            cout << prefix[right] << "\n";
        }
        else
        {
            cout << prefix[right] - prefix[left - 1] << "\n";
        }
    }

  
}


int main()
{
    int n, k;

    cin>>n>>k;

    vector<int>laddos(n);

    for(int i = 0 ; i < n  ; i++)
    cin>>laddos[i];


    vector<pair<int,int>>queries;

    for(int i = 0 ; i < k ; i++)
    {
        int a,b;
        cin>>a>>b;
        queries.push_back({a,b});
    }

    solve(laddos,n,queries,k);

}