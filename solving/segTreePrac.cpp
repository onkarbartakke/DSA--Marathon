#include<bits/stdc++.h>

using namespace std;


void Build(vector<int>&seg, vector<int>&arr, int low, int high, int ind)
{
    if(low == high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)>>1;

    Build(seg,arr,low,mid,2*ind+1);
    Build(seg,arr,mid+1,high,2*ind+2);

    seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
}


int query(vector<int>&seg, int low, int high, int ind, int l, int r)
{
    if(high < l || r<low) // [low,high,l,r] , [l,r,low,high]
    return INT_MAX;

    if(l<=low && high<=r)// [l,low,high,r]
    {
       return seg[ind];
    } 

    int mid = (high+low)>>1;

    int left = query(seg,low,mid,2*ind+1,l,r);
    int right = query(seg,mid+1,high,2*ind+2,l,r);

    return min(left,right);
}

int update(vector<int>&seg, vector<int>&arr, int ind, int low, int high, int i, int val)
{
    if(low == high)
    {
        seg[ind] = val;
        arr[i] = val;
        return val;
    }

    int mid = (low + high)>>1;

    if(i <= mid)
    seg[ind] = update(seg,arr,2*ind+1,low,mid,i,val);
    else
    seg[ind] = update(seg,arr,2*ind+2,mid+1,high,i,val);
}

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i = 0 ; i < n; i++)
    cin>>arr[i];

    vector<int>seg(4*n,-1);

    Build(seg,arr,0,n-1,0);    
}