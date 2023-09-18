#include <bits/stdc++.h>

using namespace std;

int dist(int i, int j, string s, char c)
{
    vector<int> cnt(256, 0);
    int ret = 0;
    for (int k = i + 1; k < j; k++)
    {
        if (s[k] == ' ' || s[k] == c)
            continue;

        if (cnt[s[k]] == 0)
            ret++;

        cnt[s[k]]++;
    }

    return ret;
}


int SearchLetter(string input1, string input2)
{
    string s = input1, p = input2;

    char c = p[0];

    unordered_map<char, vector<int>> mp;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
    }

    if (mp.find(c) == mp.end())
        return -1;

    vector<int> v = mp[c];

    if (v.size() == 1)
        return -1;

    int g = v.size();    
    int ans = dist(v[0],v[g-1],s,c);
    

    return ans;
}


int main()
{
    string s1, s2;

    // cin>>s1;
    // cout<<"--\n";
    // cin>>s2;

    s1 = "my name is granar";
    s2 = "a";

    cout<<"\n"<<SearchLetter(s1,s2);
}