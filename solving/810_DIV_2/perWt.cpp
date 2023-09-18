#include<bits/stdc++.h>

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

        for(int i = 1 ; i <= n ;i++)
        {
            a[i-1] = i;
        }

        // for(int i = 0 ; i+1 < n ; i = i + 2)
        // swap(a[i],a[i+1]);

        for(int i = 1 ; i < n ; i++)
        cout<<a[i]<<" ";

        cout<<a[0];

        cout<<"\n";
    }
}