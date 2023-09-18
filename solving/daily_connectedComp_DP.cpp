#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> mp;

    int i = 1;

    while (i < n)
    {
        while (i < n && arr[i - 1] == arr[i])
            i++;

        mp[arr[i - 1]]++;

        i++;
    }

    if (arr[n - 1] != arr[n - 2])
        mp[arr[n - 1]]++;

    int maxi = 0, num, ans = 0;

    for (auto it : mp)
    {
        if (maxi < it.second)
        {
            maxi = it.second;
            num = it.first;
        }

        ans += it.second;
    }

    ans -= maxi;

    cout << ans;
}


