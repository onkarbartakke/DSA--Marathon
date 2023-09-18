#include<bits/stdc++.h>

using namespace std;


int Merge(vector<int>&A, int k ,int l , int mid, int h)
{
    vector<int>temp(h-l+1);

    int i,j;
    i = l;
    j = mid+1;
    int count = 0;
    int t = 0;
    while(i<=mid && j <= h)
    {
        if(A[i] - A[j] <= k)
        {
           count += (h-j+1);
           temp[t++] = A[i++];
        }
        else
            temp[t++] = A[j++];
    }

    while(i<=mid)
    temp[t++] = A[i++];

    while(j<=h)
    temp[t++] = A[j++];
    t = 0;
    for(int i = l ; i <= h ; i++)
    {
        A[i] = temp[t++];
    }

    return count;
}
int InvCount(vector<int>&A, int k,int l, int h)
{
    int count = 0,mid;

    if(l<h)
    {
        mid = (l+h)/2;

        count += InvCount(A,k,l,mid);
        count += InvCount(A,k,mid+1,h);

        count += Merge(A,k,l,mid,h);
    }

    return count;
}
int main()
{
    int n,c,d;
    cin>>n>>c>>d;

    vector<int>a(n),b(n),A(n);


    for(int i = 0 ; i < n ; i++)
    cin>>a[i];

    for(int i = 0 ; i < n ; i++)
    cin>>b[i];

    for(int i = 0 ; i < n ; i++)
    A[i] = a[i] - b[i];

    int k = d-c;
  //  cout<<"\n\n";
    // for(int i = 0 ; i < n ; i++)
    // cout<<A[i]<<" ";
    //cout<<"\n";
    cout<<InvCount(A,k,0,n-1);

   // cout<<"\n";
    // cout<<"\n K -> "<<k<<"\n";
    // for(int i = 0 ; i < n ; i++)
    // cout<<A[i]<<" ";

}