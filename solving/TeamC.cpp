#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,m;

    cin>>n>>m;
    // n 0
    // m 1   11011 | 101
    if((n+1)*2 < m)
    {
        cout<<"-1\n";
    }
    else if(n-1 > m )
    {
        cout<<"-1\n";
    }
    else
    {
        string s = "";

        bool turn = true;

        while(n > 0 && m > 0)
        {
            if(turn)
            {
                s += "1";
                m--;

                if(m > n)
                {
                    s += "1";
                    m--;
                }

                turn = false;
            }
            else
            {
                s += "0";
                n--;
                turn = true;
            }
        }

        if(turn && m > 0)
        {
            s += "1";
            m--;

            if(m > 0)
            {
                s += "1";
                m--;
            }
        }
        else if(!turn && n>0)
        {
            s += "0";
            n--;
        }

        if(n > 0)
        {
            s = "0" + s;
            n--;
        }

        if(n == 0 && m == 0)
        cout<<s<<"\n";
        else
        cout<<"-1\n";
    }

}
