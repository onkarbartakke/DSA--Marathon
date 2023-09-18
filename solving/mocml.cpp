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

        vector<vector<int>>a(n , vector<int>(m));
        int maxi = INT_MIN;

        int r = -1 , c = 1;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                cin>>a[i][j];

                if(a[i][j] > maxi)
                {
                    r = i;
                    c = j;
                    maxi = a[i][j];
                }
            }
        }

        int h = max(r+1 , n - r);
        int w = max(c+1 , m - c);

        cout<<h*w<<"\n";
    }


}