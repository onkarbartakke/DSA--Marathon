#include <bits/stdc++.h>

using namespace std;

unordered_map<char, char> mp, rmp;
vector<bool> mapped(256, false), included(256, false);

char getUnused(char c, int r = 'a')
{
    char ret = r;

    while (included[ret] || c == ret)
        ret++;

    return ret;
}

int findLen(char c1, char c2)
{
    int len = 1;

    while(mp[c1]!=c2)
    {
        c1 = mp[c1];
        len++;

        if(len >= 26)
        return len;
    }

    return len;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;
        string s;

        cin >> s;

        string ans = "";

        char minChar = 'a';
        char last, curr;

        for (int i = 0; i < n; i++)
        {
            if (mapped[s[i]])
            {
                curr = rmp[s[i]];
                ans += curr;
            }
            else
            {

                curr = getUnused(s[i]);

                if(included[s[i]] == false)
                {
                    ans += curr;
                    mapped[s[i]] = true;
                    included[curr] = true;
                    mp[curr] = s[i];
                    rmp[s[i]] = curr;
                }
                else
                {
                    mp[curr] = s[i];
                    rmp[s[i]] = curr;

                    int len = findLen(s[i],curr);
                    //cout<<len<<"\n";
                    if(len < 25)
                    {
                        curr = getUnused(s[i],curr+1);
                        mp[curr] = s[i];
                        rmp[s[i]] = curr;
                    }

                    included[curr] = true;
                    mapped[s[i]] = true;
                    ans += curr;
                }
            }
        }

       cout<<ans<<"\n";
       for(char c = 'a' ; c <= 'z' ; c++)
       {
        included[c] = false;
        mapped[c] = false;
       }

       mp.clear();
       rmp.clear();
    }
}