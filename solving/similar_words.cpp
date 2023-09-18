#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,m;

        cin>>n>>m;

        vector<string>a(n);

        for(int i = 0 ; i <  n ; i++)
        {
            cin>>a[i];
        }

        int mini = INT_MAX;

        for(int i = 0 ; i < n-1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int curr = 0;

                for(int k = 0 ; k < m ; k++)
                {
                    curr += abs(a[i][k] - a[j][k]);
                }

                mini = min(mini,curr);
            }
        }

        cout<<mini<<"\n";
    }
}