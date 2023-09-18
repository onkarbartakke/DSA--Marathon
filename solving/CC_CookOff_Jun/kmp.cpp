#include<bits/stdc++.h>

using namespace std;

void kmp(string pattern, string str)
{
    int n = str.length();

    vector<int>lps(n,0);

    for(int i = 1 ; i < n ; i++)
    {
        int j = lps[i-1];

        while( j > 0 && str[i]!=str[j])
        {
            j = lps[j-1];
        }

        if(str[i] == str[j])
            j++;

        lps[i] = j;
    }


    int i = 0;
    int j = 0;

    while(i < str.size() && j < pattern.size())
    {
        if(str[i] == pattern[j])
        {
            i++;
            j++;

            if(i >= str.size())
            {
                cout<<"Match Found\n";
                break;
            }
        }
        else
        {
            if(i>0)
            {
                i = lps[i-1];
            }
            else
            {
                i = 0;
                j++;
            }
        }
    }
}

int main()
{
    string pattern;
    cin>>pattern;

    string str;

    cin>>str;

    kmp(pattern,str);   
}