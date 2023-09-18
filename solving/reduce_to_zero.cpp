#include<bits/stdc++.h>

using namespace std;

vector<int>pre(32769, -1);

int solve(int v)
{
    int steps = 0;

    queue<int>qu;

    qu.push(v);

    // if(v%32768 == 0)
    // return 0;

    while(!qu.empty())
    {
        steps++;

        int sz = qu.size();

        while(sz--)
        {
            int v1  = qu.front();
            qu.pop();

            if(v1 == 0)
            return steps - 1;


            int x1 = (v1+1)%32768;
            int x2 = (2*v1)%32768;

            if(x1 == 0 || x2 == 0)
            return steps;

            
            qu.push(x1);
            qu.push(x2);
        }   
    }

    return steps;

}
int main()
{
    int n;
    cin>>n;

    vector<int>A(n);

    for(int i = 0 ; i < n ; i++)
    cin>>A[i];

    vector<int>ans(n);

    for(int i  = 0 ; i < n ; i++)
    {
        if(pre[A[i]]!=-1)
        {
            ans[i] = pre[A[i]];
        }
        else
        {
            ans[i] = solve(A[i]);
            pre[A[i]] = ans[i];
        }
    }

    for(int i = 0 ; i < n ; i++)
    cout<<ans[i]<<" ";
}