#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        string s;

        cin>>s;

        int n = s.length();

        vector<int>hash(256,0);

        bool dup = false;
        bool diff = false;
        for(int i = 0 ; i < n; i++)
        {
            hash[s[i]]++;

            if(i!= n-1)
            {
                if(s[i] == s[i+1])
                dup = true;
            }


            for(int k = 97 ; k <= 122 ; k++)
            {
                if(hash[k] == 0)
                continue;

                for(int j = k + 1; j <= 122 ; j++)
                {
                    if(hash[j] == 0)
                    continue;

                    if(abs(hash[k] - hash[j]) > 2)
                    {
                        diff = true;
                        break;
                    }
                }
            }

            if(diff)
            break;
        }

        if(diff)
        {
            cout<<"No\n";
            continue;
        }
        int f = 0;

        for(auto h : hash)
        {
            if(h > 0)
            f++;
        }

        if(f == 1)
        {
            cout<<"Yes\n";
            continue;
        }

        if(f > 1 && dup)
        {
            cout<<"No\n";
            continue;
        }

         diff = false;

        for(int i = 97 ; i <= 122 ; i++)
        {
            for(int j = i + 1; j <= 122 ; j++)
            {
                if(abs(hash[i] - hash[j]) > 2)
                {
                    diff = true;
                    break;
                }
            }
        }

        
        if(diff)
        cout<<"No\n";
        else
        cout<<"Yes\n";

    }
}