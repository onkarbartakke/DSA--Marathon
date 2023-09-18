#include<bits/stdc++.h>
#define ll long long
using namespace  std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<ll>a(n);

        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];
        }

        if(n%2 == 1)
        {
            cout<<"Mike\n";
        }
        else
        {
            int idx = min_element(a.begin() , a.end()) - a.begin();

            if(idx&1)
            {
                cout<<"Mike\n";
            }
            else
            {
                cout<<"Joe\n";
            }
        }
    }
}