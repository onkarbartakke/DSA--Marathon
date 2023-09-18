#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<int>arr(200007);

vector<int>mp(200007,0);


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;

    int cnt = 0;

    
    for(int i = 1; i <= n ; i++)
    {
        cin>>arr[i];

        mp[arr[i]]++;

        if(mp[arr[i] - 1] == 0)
        cnt++;
    }

    cout<<cnt;


}