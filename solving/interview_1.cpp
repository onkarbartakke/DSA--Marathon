#include<bits/stdc++.h>

using namespace std;
// N tiles in staright line, 
/* 
On each tile there is some gold
If i am in i can go in j iff i+j is odd
at most k jumps
can start from any tile

I need to maximise the gold

i+j odd, odd = even+odd, odd+even

N= 5, K = 2
a ={ 5,2,4,3,5}  maxGold = 13
     0,1,2,3,4

     N <=100   0 < k


int i , even/odd


solve(int i, int k)
{
    K jumps left,


    if(k == 0 )
    return a[i];

    if(dp[i][k]!=-1)
    return dp[i][k];


    retval = INT_MIN;

 for(int j = i + 1; j < min(N,K) ; j = j + 2)
 {
      tempVal = a[i] + solve(j,k-1);

      retval = max(retVal, tempVal); 
 }

    return dp[i][k] = retval;
}

for(int i = 0 ; i < N ; i++)
{
    tempVal = solve(i,K);

    maxGold = max(maxGold, tempVal);
}

10^9 computions in 1 sec

N*K = 

if N = 10^6 and k is 0 <-> N-1; == O(N) and NLogN  (general case)


N*log(K)


// a = {1,2,3,4,5,6}

2 heaps , even Heaps 
        odd Heaps

N nums = Nlog(N)



*/
int main()
{
    long long int N,k;
    cin>>N>>k;

    vector<long long>a(N);

    for(int i = 0 ; i < N ; i++)
    cin>>a[i];

    vector<long long>even,odd;

    for(long long i = 0 ; i < N ; i++)
    {
        if(i&1)
        odd.push_back(a[i]);
        else
        even.push_back(a[i]);
    }

    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());

    long long m1 = 0 , m2 = 0 ,e = 0 , o = 0;

    bool flag = true;
    while(k-- && e<even.size() && o<odd.size())
    {
        if(flag)
        {
            m1 += even[e];
            m2 += odd[o];
        }
        else
        {
            m1 += odd[o];
            m2 += even[e];
        }

        flag = !flag;

        e++;
        o++;
    }

    long long int maxGold = max(m1,m2);
    if(k == N-1)
    maxGold = accumulate(a.begin(),a.end(),0);
   

}


/* 

N len arr
partition in K subarrs

Need to make new arr of len k
new arr in B

B[i] is sum of ith subarry

minimize max val of B[i];

N is 10^3

vector<int>B(k);


maxVal;
partition(int p , int i, int k)
{
    if(k == 1)
    {
        B[p] = prefixSum[N-1] - preFixsum[i] + a[i];
       
       for(auto it : B)
       {
           maxNow = max(maxNow,it);
       }

       
        maxVal = min(maxVal, maxN)
    }


    for(int j = i ; j < N-K; j++)
    {
        B[p] = prefixSum[j] - preFixSum[i] + a[i];  (i -- j)
        maxNow = max(maxNow,B[p]);
        partition(p+1,j+1,k-1,maxNow)
    }
}

partition(0,0,k);

*/