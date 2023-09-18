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

        vector<int>a(2*n);

        for(int i = 0 ; i < 2*n ; i++)
        cin>>a[i];


        sort(a.begin() , a.end());


        bool possible = true;
        int cnt = 0;
        int i = 0 , j = n;
        int same = 0;
        
        while(i<n)
        {
            if(a[i]!=a[j])
            cnt++;
            else if(a[i] == a[j])
            same++;

            i++;
            j++;
        }

        if(cnt >= same || same == cnt+1)
        cout<<"YES\n";
        else
        {
            i = 0;
            j = (2*n-1);
            cnt = 0, same = 0;


            while(j>i)
            {
                if(i == j)
                break;

                if(a[i] == a[j])
                same++;
                else
                cnt++;

                i++;
                j--;
            }

            if(cnt >= same || same == cnt+1)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
}