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

        vector<int>a(2*n);
        int N = 2*n;

        int odd = 0 , even = 0;
        for(int i = 0; i < N ; i++)
        {
            cin>>a[i];

            if(a[i]&1)
            odd++;
            else
            even++;
        }

        if(odd%2 == 0 && even%2 ==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}