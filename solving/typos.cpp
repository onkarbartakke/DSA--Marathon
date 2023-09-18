#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;
    cin >> s;

    string p = "";

    int i = 0;
    int n = s.length();
    while (i < n)
    {
        int j = i;

        int count = 1;
        while (j + 1 < n && s[j] == s[j + 1])
        {
            count++;
            j++;
        }

        if (count == 1 || count == 2)
        {
            while (count)
            {
                p += s[i];
                count--;
            }

            i = j + 1;
        }
        else if (count > 2)
        {
            p += s[i];
            p += s[i];
            i = j + 1;
        }


    }
   // cout<<p<<"\n";
   // cout<<p.length()<<"\n";
    i = 0;
    string ret = "";


    while(i < p.length())
    {
       char c = p[i];

       ret += c;

       if(i+1 < p.length() && p[i]!=p[i+1])
       {
           i++;
           continue;
       }
       else if(i+1 >= n)
       break;
       else if(i+1 < p.length() && p[i] == p[i+1])
       {
           ret += c;
           i++;
       }

       int j = i+1;

       if(j >= p.length())
       break;

       c = p[j];
       ret += c;

       if(j+1 >= p.length())
       break;
       else if(j+1 < p.length() && p[j] == p[j+1])
       i = j + 2;
       else if(j+1 < p.length() && p[j]!=p[j+1])
       i = j + 1;
    
    }
    
    cout<<ret<<"\n";
    //cout<<ret.length()<<"\n";
}