#include <bits/stdc++.h>

using namespace std;

int steppingNumbers(int n, int m)
{
    // Code Here

    int ans = 0;

    queue<int> qu;

    if (n == 0)
        ans++;

    for (int i = 1; i <= 9; i++)
    {
        qu.push(i);
    }

    while (!qu.empty())
    {
        int ele = qu.front();
        qu.pop();

        if (ele <= m && ele >= n)
            ans++;

        int lastDigit = ele % 10;

        int newEle;

        if (lastDigit == 9)
        {
            newEle = (ele * 10) + (lastDigit - 1);

            if (newEle <= m)
                qu.push(newEle);
        }
        else if (lastDigit == 0)
        {
            newEle = (ele * 10) + (lastDigit + 1);
            if (newEle <= m)
                qu.push(newEle);
        }
        else
        {
            newEle = (ele * 10) + (lastDigit + 1);
            if (newEle <= m)
                qu.push(newEle);

            newEle = (ele * 10) + (lastDigit - 1);
            if (newEle <= m)
                qu.push(newEle);
        }
    }

    return ans;
}


int main()
{
    int n,m;

    cin>>n>>m;

    cout<<"\n\n"<<steppingNumbers(n,m);
}