#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll getMinWindow(vector<ll>&A, int n , int q, ll totalSum)
{
    int win = n - q;

    ll ans = 0;

   
    ll winSum = 0;

    for(int i = 0 ; i < win ; i++)
    {
        winSum += A[i];
    }

    ans = max(ans, totalSum - winSum);

    for(int i = win ; i < n ; i++)
    {
        winSum += A[i];
        winSum -= A[i - win];

        ans = max(ans, totalSum - winSum);
    }


    return ans;
}

ll Score(vector<ll>&A, vector<ll>&B, int n, int m, int k, int q, ll TA, ll TB)
{
    if(q > n || k-q > m)
    return 0;

    ll ans = 0;

    ll Amark , Bmark;

    ans = getMinWindow(A,n,q,TA);

    ans += getMinWindow(B,m,k-q,TB);

    return ans;
}

ll GetMaxScore(vector<ll>&A, vector<ll>&B, int n, int m, int k)
{
    ll ans = 0;

    if(k == 0)
    return 0;

    if(n+m == k)
    {
        ll ini = 0;

        ll ans = accumulate(A.begin(),A.end(),ini);

        ans += accumulate(B.begin() , B.end(), ini);

        return ans;
    }

    ll TA = 0 , TB = 0;

    for(auto it : A)
    TA += it;

    for(auto it : B)
    TB += it;


    for(int q = 0 ; q <= k ; q++)
    {
        ll currAns = Score(A,B,n,m,k,q,TA,TB);

      //  cout<<"Q : "<<q<<"   "<<currAns<<"\n";
        ans = max(ans, currAns);
    }

    return ans;
}
int main()
{
    int t;
    int count = 1;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n;
        vector<ll>A(n);

        for(int i = 0 ; i < n ; i++)
        cin>>A[i];

        cin>>m;

        vector<ll>B(m);

        for(int i = 0 ; i < m ; i++)
        cin>>B[i];

        int k;

        cin>>k;

        ll maxScore = GetMaxScore(A,B,n,m,k);

        cout<<"Case #"<<count<<": "<<maxScore<<"\n";
        count++;

    }    
}