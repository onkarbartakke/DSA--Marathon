#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int count = 0;

    if (n == m)
        cout << "0\n";
    else
    {
        unordered_set<int> st;

        st.insert(n);

        queue<int> qu;

        qu.push(n);
        bool found = false;
        while (!qu.empty())
        {
            int sz = qu.size();
            bool change = false;
            while (sz--)
            {
                int ele = qu.front();
                qu.pop();

                if (ele * 2 == m)
                {
                    found = true;
                }
                else if (ele - 1 > 0 && ele - 1 == m)
                {
                    found = true;
                }

                if (st.find(ele * 2) == st.end() && ele * 2 < 2 * m)
                {
                    st.insert(ele * 2);
                    change = true;
                    qu.push(ele * 2);
                }

                if (ele - 1 > 0 && st.find(ele - 1) == st.end())
                {
                    st.insert(ele - 1);
                    change = true;
                    qu.push(ele - 1);
                }

                if (found)
                    break;
            }

            if (change)
                count++;

            if (found)
                break;
        }

        if (found)
            cout << count << "\n";
        else
            cout << "-1\n";
    }
}