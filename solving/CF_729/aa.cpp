#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        string s;

        cin>>s;

        int l = s.length();

        if(l == 2)
        {
            swap(s[0],s[1]);
            cout<<s[0]<<"\n";
        }
        else
        {
            int mini = INT_MAX;

            for(int i = 0 ; i < l ; i++)
            {
                mini = min(mini, s[i]-'0');
            }

            cout<<mini<<"\n";
        }
    }
}