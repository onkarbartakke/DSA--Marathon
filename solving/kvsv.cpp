#include <bits/stdc++.h>

using namespace std;

int solve(string s, int K)
{
    // code here

    int n = s.length();
    vector<int> arr;
    vector<bool> infect(false, n);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            infect[i] = true;
            arr.push_back(i);
        }
    }

    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int idx = arr[i];
        cnt++;

        // cout<<idx<<" ";
        int leftidx = max(0, idx - K);
        int rightidx = min(n - 1, idx + K);

        for (int j = idx - 1; j >= leftidx; j--)
        {
            if (infect[j] == false)
            {
                cnt++;
                infect[j] = true;
                // cout<<j<<" ";
            }
            else
                break;
        }

        for (int j = idx + 1; j <= rightidx; j++)
        {
            if (infect[j] == false)
            {
                cnt++;
                infect[j] = true;
                // cout<<j<<" ";
            }
            else
                break;
        }
    }

    return cnt;
}


int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    cout<<"\n\n"<<solve(s,k);
}