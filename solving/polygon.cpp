#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<string>v(n);

        for(int i = 0 ; i < n ; i++)
        {
            cin>>v[i];
        }

        bool possible = true;

        for(int i = n - 1 ; i >= 0 ; i--)
        {
            for(int j = n - 1 ; j >= 0 ; j--)
            {
                if(i == n-1 || j == n-1)
                continue;
                else if(v[i][j] == '1')
                {
                    if(v[i+1][j] == '1' || v[i][j+1] == '1')
                    continue;
                    else
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if(!possible)
            break;
        }

        if(possible)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}