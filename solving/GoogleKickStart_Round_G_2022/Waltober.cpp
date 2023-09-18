#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        int n,m,p;

        cin>>m>>n>>p;

        int s[m][n];
        p--;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            cin>>s[i][j];
        }

        ll ans = 0;

        int id,sc = 0;

        for(int j = 0 ; j < n ; j++)
        {
            sc = 0;
            for(int i = 0 ; i < m ; i++)
            {
                if(sc < s[i][j])
                {
                    sc = s[i][j];
                    id = i;
                }
            }

            if(sc > s[p][j])
            {
                ans += (sc - s[p][j]);
            }
        }


        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}