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

        vector<int>arr(n);

        for(int i = 0 ; i < n ; i++)
        cin>>arr[i];

        sort(arr.begin() , arr.end() , greater<int>());

        if(arr[0] == arr[1])
        {
            swap(arr[1],arr[n-1]);
        }

        if(arr[0] == arr[1])
        cout<<"NO\n";
        else
        {
            cout<<"YES\n";

            for(auto it : arr)
            cout<<it<<" ";
            
            cout<<"\n";
        }
    }
}