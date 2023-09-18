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

        for(int i = 0 ; i < n ; i++)
        cin>>a[i];

        int count = 0;

        int len = 1;

        while(len<=n)
        {
           int R = n - len;
           R--;
           len = len*2;

           int L = n - len;
           int i = R;
           bool flag = true;
           while(i>=L && i>=0)
           {
               if(a[i]!=a[R+1])
               {
                   //count++;
                   a[i] = a[R+1];

                   if(flag)
                   {
                       flag = false;
                       count++;
                   }
                  
               }
               i--;
           }
        }

        cout<<count<<"\n";
    }
}