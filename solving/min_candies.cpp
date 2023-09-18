#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int mini = INT_MAX , n;
        cin>>n;

        vector<int>a(n);

        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];

            mini = min(mini, a[i]);
        }

        long int count = 0;

        for(int i = 0 ; i < n ; i++)
        {
            count += (a[i] - mini);
        }

        cout<<count<<"\n";
    }
}