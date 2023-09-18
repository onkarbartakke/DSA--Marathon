#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);

        for(int i = 0 ; i < n ; i++)
        cin>>a[i];

        
        int g = a[0];
        for(int i = 0 ; i < n ; i++)
        {
            g = __gcd(g,a[i]);
        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(a[i]!=g)
            cnt++;
        }

        cout<<cnt<<"\n";
    }
}