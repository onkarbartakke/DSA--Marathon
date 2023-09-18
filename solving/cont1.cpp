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
       vector<int>b(n);

       for(int i = 0 ; i < n ; i++)
       {
           cin>>a[i];
       }
    
        for(int i = 0 ; i < n ; i++)
       {
           cin>>b[i];
       }
       
       int maxa = *max_element(a.begin(),a.end());
       int maxb = *max_element(b.begin(),b.end());

       if(maxb > maxa)
       {
           a.swap(b);
           swap(maxa,maxb);
       }

       int i = max_element(b.begin(),b.end()) - b.begin();

       while(a[i]<b[i])
       {
            //cout<<a[i]<<"  "<<b[i]<<"\nSwap\n";
           swap(a[i],b[i]);
            //cout<<a[i]<<"  "<<b[i]<<"\n";
           i = max_element(b.begin(),b.end()) - b.begin();
        }

       cout<<maxa*b[i]<<"\n";
    }
}