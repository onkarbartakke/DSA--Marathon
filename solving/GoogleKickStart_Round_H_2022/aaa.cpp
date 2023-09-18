#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        ll l,n;
        cin>>l>>n;

        vector<pair<int,char>>vp;

        ll rem = 0 , ans = 0;
        char prev = 'C';
        for(int i = 0 ; i < n ; i++)
        {
            int d;
            char c;

            cin>>d>>c;

            vp.push_back({d,c});

            if(prev == c)
            {
                ans += (rem + d)/l;
                rem = (rem+d)%l;
            }
            else
            {
               if(d >= rem)
               {
                    d = d - rem;
                    prev = c;
                    rem = 0;

                    ans += (rem+d)/l;
                    rem = (rem+d)%l;
               }
               else
               {
                    rem = rem - d;
                    rem = -1*rem;
                    prev = c;
               }
            }
        }


        cout<<"Case #"<<cnt<<": "<<ans<<"\n";
        cnt++;
    }
}