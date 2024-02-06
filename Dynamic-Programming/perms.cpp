#include<bits/stdc++.h>
#define ll long long


using namespace std;


int findSmallestNum(int n)
{
 
    int larPowOfTwo = floor(log2(n));
 
    larPowOfTwo = 1 << larPowOfTwo;
 
    return larPowOfTwo - 1;
}

vector<int> InitialTrophyCount(vector<int>TestCases)
{
    vector<int>ans;

    for(auto t : TestCases)
    {
        int lastNum =  findSmallestNum(t);
        ans.push_back(lastNum);
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;

    vector<int>t(n);

    for(int i = 0 ;  i < n ; i++)
    cin>>t[i];

    vector<int>ans = InitialTrophyCount(t);
    cout<<"\n";
    for(int i = 0 ; i < n ; i++)
    cout<<ans[i]<<" ";
}