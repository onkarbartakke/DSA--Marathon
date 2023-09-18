#include<bits/stdc++.h>

using namespace std;

long long minDays(vector<int>&A, int n)
{
    long long days = 1, spareEven = 0, spareOdd = 0;

    int mx = *max_element(A.begin(),A.end());

    priority_queue<int, vector<int> , greater<int> >pq;

    for(int i = 0 ; i < n ; i++)
    pq.push(A[i]);

    while(pq.top()!=mx)
    {
        int t1 = pq.top();
        pq.pop();

        int h = mx - t1;

        
    }

}
int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n;
        vector<int>A(n);

        cin>>n;

        for(int i = 0 ; i < n ; i++)
        cin>>A[i];

        cout<<minDays(A,n);
        cout<<"\n";
    }
}