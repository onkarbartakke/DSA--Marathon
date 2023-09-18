#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

long long rightShuffle(long long num)
{
    int len = 0;
    long long n = num;

    while (n)
    {
        len++;
        n /= 10;
    }
    if (len == 1)
        return num;

    long long last = num % 10;

    long long ret = ((long long)pow(10, len - 1)) * last + (num / 10);

    return ret;
}
int minimumCoins(int n, int x)
{
    // Write your code here.
    queue<long long> qu;

    qu.push(1);

    vector<bool> vis(1e6 + 5, false);

    vis[1] = true;
    int moves = 0;

    while (!qu.empty())
    {
        int sz = qu.size();

        while (sz--)
        {
            auto num = qu.front();
            qu.pop();

            if (num == n)
                return moves;

            long long op1 = num * x;
            long long op2 = rightShuffle(num);

            if (op1 == n || op2 == n)
                return moves + 1;

            if (!vis[op1])
            {
                vis[op1] = true;
                qu.push(op1);
            }

            if (!vis[op2])
            {
                vis[op2] = true;
                qu.push(op2);
            }
        }

        moves++;
    }

    return -1;
}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,x;

        cin>>n>>x;

        int moves = minimumCoins(n,x);

        cout<<moves<<"\n";
    }
}