#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>h(2*n);


        for(int i = 0 ; i < 2*n ; i++)
        {
            cin>>h[i];
        }
        
        sort(h.begin() , h.end());
        bool possible = true;


        for(int i = n ; i < 2*n ; i++)
        {
            if(h[i] - h[i-n] < x)
            {
                possible = false;
                cout<<"NO\n";
                break;
            }
        }

        if(possible)
        cout<<"YES\n";
    }
}