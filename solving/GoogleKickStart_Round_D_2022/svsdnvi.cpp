#include<bits/stdc++.h>


using  namespace std;


int solve(int A, int B, int C, int D, int X)
{
    C = 2*C;
    D = 2*D;

    vector<int>mols;

    mols.push_back(A);
    mols.push_back(B);
    mols.push_back(C);
    mols.push_back(D);

    sort(mols.begin() , mols.end());

    vector<int>dp(X+1,INT_MIN);

    dp[0] = 0;


    for(int i = mols[0] ; i <= X ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(i - mols[j] >= 0 && dp[i - mols[j]]!=INT_MIN)
            dp[i] = max(dp[i] , 1 + dp[i - mols[j]]);
        }
    }

    if(dp[X] == INT_MIN)
    return 0;
    return dp[X];


}
int main()
{
    cout<<solve(2,4,1,1,11);
    
}