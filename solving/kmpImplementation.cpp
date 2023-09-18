#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin>>s;

    n = s.length();

    vector<int>lps(n,0);

    int j;
    for(int i = 1 ; i < n ; i++)
    {
        j = lps[i-1];


        while(j > 0 && s[i]!=s[j])
        {
            j = lps[j-1];
        }

        if(s[i] == s[j])
        j++;

        lps[i] = j;
    }

    for(auto it : s)
    cout<<it<<"  ";

    cout<<"\n";

    for(auto it : lps)
    cout<<it<<"  ";
}