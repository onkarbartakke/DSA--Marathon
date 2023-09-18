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

        int max1 = INT_MIN , max2 = INT_MIN , min1 = INT_MAX , min2 = INT_MAX;

        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i];

            if(a[i] >= max1)
            {
                max2 = max1;
                max1 = a[i];
            }
            else if(a[i] < max1 && a[i] >= max2)
            max2 = a[i];

            if(a[i] <= min1)
            {
                min2 = min1;
                min1 = a[i];
            }
            else if(a[i] > min1 && a[i] <= min2)
            min2 = a[i];
        }
       // cout<<max1<<" "<<max2<<" "<<min1<<" "<<min2<<"\n\n";
        cout<<(max1 - min1) + (max2 - min2)<<"\n";
    }
}