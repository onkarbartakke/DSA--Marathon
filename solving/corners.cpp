#include<bits/stdc++.h>


using namespace std;


int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,m;

        vector<string>mat(n);

        for(int i = 0 ; i < n ; i++)
        cin>>mat[i];

        queue<pair<int,int>>qu;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j] == '0')
                qu.push({i,j});
            }
        }

        if(qu.size() == n*m)
        {
            cout<<"0\n";
            continue;
        }
        else if(qu.size() == 0)
        {
            
        }

        int cnt = 0;


        while(!qu.empty())
        {
            auto p = qu.front();
            qu.pop();



        }

    }
}