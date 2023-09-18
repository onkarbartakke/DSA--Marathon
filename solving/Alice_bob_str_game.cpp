#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    string s;

    while(t--)
    {
        cin>>s;

        int n = s.length();

        int sr = 0;

        if(n == 1)
        {
            sr = s[0] - 'a' + 1;

            cout<<"Bob "<<sr<<"\n";
        }
        else if(n%2 == 0)
        {
            for(auto ch : s)
            {
                sr += (ch - 'a' + 1);
            }

            cout<<"Alice "<<sr<<"\n";
        }
        else
        {
            if(s[0] > s[n-1])
            {
                for(int j = 0 ; j < n-1 ; j++)
                {
                    sr += (s[j] - 'a' + 1);
                }

                
                if(sr > (s[n-1] - 'a' + 1))
                {
                    cout<<"Alice "<<sr - (s[n-1] - 'a' + 1)<<"\n";
                }
                else
                {
                    cout<<"Bob "<<(s[n-1] - 'a' + 1) - sr<<"\n";
                }
            }
            else
            {
                for(int j = 1 ; j < n; j++)
                {
                    sr += (s[j] - 'a' + 1);
                }

                if(sr > (s[0] - 'a' + 1))
                {
                    cout<<"Alice "<<sr - (s[0] - 'a' + 1)<<"\n";
                }
                else
                {
                    cout<<"Bob "<<(s[0] - 'a' + 1) - sr<<"\n";
                }
            }
        }
    }
}