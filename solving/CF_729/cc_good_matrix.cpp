#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>>mat(n,vector<int>(m));

        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j++)
            cin>>mat[i][j];
        }

        bool flag = true;
        vector<int>swaps;

        vector<int>checks;


        for(int i = 0 ; i < n ; i++)
        {
            auto v = mat[i];
            sort(v.begin(),v.end());

            int mismatch = 0;
            vector<int>pos;

            for(int j = 0 ; j < m ; j++)
            {
                if(v[j]!=mat[i][j])
                {
                    mismatch++;
                    pos.push_back(j);
                }
            }


            if(mismatch > 2)
            {
                cout<<"-1\n";
                flag = false;
                break;
            }
            else if(mismatch == 2)
            {
                if(swaps.size() == 0)
                {
                    swaps = pos;
                }
                else if(swaps.size() == 2)
                {
                    if(swaps[0]!=pos[0] || swaps[1]!=pos[1])
                    {
                        flag = false;
                        cout<<"-1\n";
                        break;
                    }
                }
            }
            else if(mismatch == 0)
            {
                if(swaps.size() == 0)
                checks.push_back(i);
                else
                {
                    if(v[swaps[0]]!=v[swaps[1]])
                    {
                        flag = false;
                        cout<<"-1\n";
                        break;
                    }
                }

            }
        }


        if(swaps.size() == 0)
        {
            cout<<"1 1\n";
            continue;
        }

        for(int i = 0 ; i < checks.size() ; i++)
        {
            int j = checks[i];

            if(mat[j][swaps[0]]!=mat[j][swaps[1]])
            {
                cout<<"-1\n";
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout<<"-->  ";
            cout<<swaps[0]+1<<" "<<swaps[1]+1<<"\n";
        }
    }
}