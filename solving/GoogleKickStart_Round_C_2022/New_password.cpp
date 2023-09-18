#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;
    int f = 1;
    while(t--)
    {
        int n;

        cin>>n;

        string s;

        cin>>s;

        bool num = false, splChar = false, captial = false, small = false, isSeven = false;

        if(n >= 7)
        isSeven = true;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]>='0' && s[i]<='9')
            num = true;
            else if(s[i]>='a' && s[i] <= 'z')
            small = true;
            else if(s[i] >= 'A' && s[i] <= 'Z')
            captial = true;
            else if(s[i] == '#' || s[i] == '*' || s[i] == '@' || s[i] == '&')
            splChar = true;
        }

        if(!num)
        s.push_back('9');
        if(!splChar)
        s.push_back('@');
        if(!captial)
        s.push_back('A');
        if(!small)
        s.push_back('k');

        while(s.length() < 7)
        s.push_back('r');

        cout<<"Case #"<<(f)<<": "<<s<<"\n";
        f++;
    }
}