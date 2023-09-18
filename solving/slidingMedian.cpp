#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<ll> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];


    priority_queue<ll , vector<ll> >maxheap;
    priority_queue<ll , vector<ll> , greater<ll>>minheap;
    unordered_map<ll,int>mp;


    for(int i = 0 ; i < k ; i++)
    maxheap.push(nums[i]);

    for(int i = k/2 ; i > 0 ; i--)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }

    int i = k;
   

    vector<int>ans;
    while(true)
    {
        ans.push_back(maxheap.top());

        if(i == nums.size())
        break;

        ll n = nums[i] , m = nums[i-k];
        int balance = 0;
        i++;

        if(m <= maxheap.top())
        {
            balance--;

            if(m == maxheap.top())
            maxheap.pop();
            else
            mp[m]++;
        }
        else
        {
            balance++;

            if(m == minheap.top())
            minheap.pop();
            else
            mp[m]++;
        }


        if(!maxheap.empty() && n <= maxheap.top())
        {
            maxheap.push(n);
            balance++;
        }
        else
        {
            minheap.push(n);
            balance--;
        }

        if(balance < 0)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(balance > 0)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }


        while(!maxheap.empty() && mp[maxheap.top()])
        {
            mp[maxheap.top()]--;
            maxheap.pop();
        }


        while(!minheap.empty() && mp[minheap.top()])
        {
            mp[minheap.top()]--;
            minheap.pop();
        }
    }


    for(auto it : ans)
    cout<<it<<" ";
}