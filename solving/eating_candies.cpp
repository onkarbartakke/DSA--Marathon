#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,q;

        cin>>n>>q;

        vector<int>a(n);

        for(int i = 0 ; i<n ; i++)
        cin>>a[i];

        sort(a.begin() , a.end() , greater<int>());

        while(q--)
        {
            int k;
            cin>>k;

            int curr = 0;

            bool flag = false;
            int c = 0;
            for(int i = 0 ; i < n ; i++)
            {
                curr += a[i];
                c++;
                if(curr>=k)
                {
                    flag = true;
                    break;
                }

            }
            //cout<<"ans : ";
            if(flag)
            cout<<c<<"\n";
            else
            cout<<"-1\n";
        }
    }
}