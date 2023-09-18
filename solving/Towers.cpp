#include <bits/stdc++.h>

using namespace std;

vector<int> arr(200007);
multiset<int> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int ans = 1;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {

        if (st.empty())
            st.insert(arr[i]);
        else
        {

            auto it = st.upper_bound(arr[i]);

            if (it != st.end() && (*it) > arr[i])
            {
                st.erase(it);
            }

            st.insert(arr[i]);
        }
    }

    cout << st.size();
}