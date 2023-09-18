#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a = 0 , b = 0;
        string s;
        cin>>s;


        for(int i = 0 ; i < 6 ; i++)
        {
            


            if(i<3)
            a += (s[i] - '0');
            else
            b += (s[i] - '0');

        }

        if(a == b)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}