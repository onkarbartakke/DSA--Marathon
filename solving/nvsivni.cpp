#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        if (n <= 2 || arr[0] == arr[n - 1])
        {
            cout << "YES\n";
        }
        else
        {
            int fst = arr[0], lst = arr[n - 1];

            bool possible = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == fst && i + 1 < n && arr[i + 1] == lst)
                {
                    possible = true;
                    break;
                }
            }

            if (possible)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
