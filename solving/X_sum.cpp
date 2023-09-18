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
        vector<vector<int>>mat(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                cin>>mat[i][j];
            }
        }

        unordered_map<int,int>d1;
        unordered_map<int,int>d2;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                d1[i-j] += mat[i][j];
                d2[i+j] += mat[i][j];
            }
        }

        int maxi = INT_MIN;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int diag1 = d1[i-j];
                int diag2 = d2[i+j];

                maxi = max(maxi , diag1 + diag2 - mat[i][j]);
            }
        }

        cout<<maxi<<"\n";
    }
}