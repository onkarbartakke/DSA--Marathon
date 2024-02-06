#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int m;
        cin>>m;

        vector<string>s(2);

        cin>>s[0];
        cin>>s[1];

        bool ok = true;
        int pos = -1;
        for(int i = 0 ; i < m ; i++)
        {
            if(s[0][i] == 'W' && s[1][i] == 'W')
            {
                ok = false;
                break;
            }
            else if(s[0][i]!=s[1][i])
            {
                pos = i;
                break;
            }
        }

        if(pos == -1)
        {
            cout<<"YES\n";
            continue;
        }

        int cur = 0;

        if(s[0][pos] == 'B')
        cur = 0;
        else
        cur = 1;

        for(int i = pos ; i < m ; i++)
        {
            if(s[cur][i] == 'W')
            {
                ok = false;
                break;
            }
            else if(s[cur^1][i] == 'B')
            {
                cur ^= 1;
            }
        }

        if(ok)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}