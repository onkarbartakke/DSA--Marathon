#include <bits/stdc++.h>

using namespace std;

int findMin(int n, char a[])
{
    // code here
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top() == a[i])
            st.push(a[i]);
        else
        {
            char c = st.top();
            st.pop();

            if ((c == 'R' && a[i] == 'G') || c == 'G' && a[i] == 'R')
                st.push('B');
            else if ((c == 'G' && a[i] == 'B') || (c == 'B' && a[i] == 'G'))
                st.push('R');
            else
                st.push('G');

            while (st.size() >= 2)
            {
                char c1 = st.top();
                st.pop();

                char c2 = st.top();
                st.pop();

                if (c1 == c2)
                {
                    st.push(c2);
                    st.push(c1);
                    break;
                }

                if ((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R'))
                    st.push('B');
                else if ((c1 == 'G' && c2 == 'B') || (c1 == 'B' && c2 == 'G'))
                    st.push('R');
                else
                    st.push('G');
            }
        }
    }

    while (st.size() >= 2)
    {
        char c1 = st.top();
        st.pop();

        char c2 = st.top();
        st.pop();

        if (c1 == c2)
        {
            st.push(c2);
            st.push(c1);
            break;
        }

        if ((c1 == 'R' && c2 == 'G') || (c1 == 'G' && c2 == 'R'))
            st.push('B');
        else if ((c1 == 'G' && c2 == 'B') || (c1 == 'B' && c2 == 'G'))
            st.push('R');
        else
            st.push('G');
    }

    int ans = st.size();
    cout<<"\n\n";
    while(!st.empty())
    {
        cout<<st.top()<<" ";

        st.pop();
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    char a[n+1];

    for(int i = 0 ; i < n ; i++)
    cin>>a[i];

    int ans = findMin(n,a);


    cout<<"\n\n"<<ans;
}

/*
843
R R B R B B B G G G B R R B R G R R R R B G G B G B R B R R B B R G G B B R R G B G R G B R B B B B B R B R G B G G R R G B G R G B G B G B B R R B G R R B B B R B R B G G R G G B G R R G R G B R G B B R G G R R R R B G G G B G B R G G R G R R R B B B B G B B R R G R B G B G R G G G G R G B B B B G B G G B B R R G B G B B B B G R B R G B B G R R R R G B R B B B B G B G R G G B G B R R R R B B G G R B G G G G G G G G B R G G G R G R G G B B B G R B B G B R B B G R B B R B B R B G R R G R B G B R G G R R R B G B R R G R R B B B G B R B G R B R R B B G R G R R G B R G G B B B B R B G G G G G G R B B R R G B G R B B G B B G B R G R B B G R B B R B B R B B R R R G R R B B R G G B B R R R R G B B R B G R R R G G B R R G B B B G B G R R G G B G R B G B B B R R R R R B B G R G R R B G B B B B B G B G B G G G B G B G B G R G G R B R R B R B G B R B R G G G G B B R R R R G G G G B B R B R B G B G R B G R R G G B G B B B R G R B R B B G R B G B B B G R B R R G G R R G G G B R B G G B G G B G R G R R B R G R B B B G B G R B G R G G R R R B B R B B R G B B G G G R G R R B B G B B B G G B G B G G R G R G G B R R B B G R B G B B G R R G G G R G B R B R G R R R R B G R R G B G G R R R B B R R B R R G G R G R B R B B B B G G G B G R B B R R G B G R G R G G R G G R B B R R G G G R R B G R G R G B G G R B R R R R R G R R G R R B B B B B R R G B G R G G B B B R B B B G B B R B B B G G G R R B B R R G B R R B B G B G G G G R B B R R B B G G R B G G B B G R G G G R R R G B R B B R B R R R R B B B R B B B R B B R G R R B B B G B B G B G B R G R G B R G G R R R B B G G G R G G G B B R G B G B B B B R G B R B G G R G G R R B G G R G R R G G G B R G R R R B G G G B B G R R B R R B B*/