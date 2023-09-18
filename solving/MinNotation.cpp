#include <bits/stdc++.h>

using namespace std;

char min(char a, char b)
{
    if(a < b)
    return a;
    else
    return b;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;

        cin >> s;

        int n = s.length();

        multiset<char> st;

        st.insert(s[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            char c1 = (*st.begin());

            if (s[i] > c1)
            {

                char c = min('9', s[i] + 1);
                st.insert(c);
            }
            else
            {
                st.insert(s[i]);
            }
        }

        string ans = "";

        for (auto it : st)
            ans += it;

        cout << ans << "\n";
    }
}