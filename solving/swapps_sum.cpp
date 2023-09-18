#include<bits/stdc++.h>

using namespace std;

long long solve(int i, vector<int>&A, vector<int>&B, int n)
{
    if(i == n - 1)
    return 0;

    long long sumUntil = solve(i+1,A,B,n);

    if(abs(A[i+1] - A[i]) + abs(B[i+1] - B[i]) > abs(A[i+1] - B[i]) + abs(B[i+1] - A[i]))
    {
        swap(A[i],B[i]);
    }

    return sumUntil + abs(A[i+1] - A[i]) + abs(B[i+1] - B[i]);
}

long long minPossible(vector<int>&A, vector<int>&B, int n)
{
    return solve(0,A,B,n);
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;

        cin>>n;

        vector<int>A(n) , B(n);

        for(int i = 0 ; i < n ; i++)
        {
            cin>>A[i];
        }

        for(int i = 0 ; i< n ; i++)
        cin>>B[i];

        cout<<minPossible(A,B,n);

        cout<<"\n";
    }
}