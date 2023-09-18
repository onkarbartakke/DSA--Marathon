#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];


    vector<bool>possible(1e5+1,false) , curr(1e5+1,false);

    curr[0] = true;
    possible[0] = true;


    for(int i = 0 ; i < n ; i++)
    {
        int currDeno = coins[i];

        for(int j = 0 ; j <= 1e5 ; j++)
        {
            if(possible[j] && j+currDeno <= 1e5)
            {
                curr[j] = true;
                curr[j+currDeno] = true;
            }
            
        }

        possible = curr;
    }


    vector<int>vals;

    for(int i = 1 ; i <= 1e5 ; i++)
    {
        if(possible[i])
        {
            vals.push_back(i);
        }
        
    }

    cout<<vals.size()<<"\n";

    for(auto it : vals)
    cout<<it<<" ";

    cout<<"\n";
}