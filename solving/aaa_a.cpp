#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unordered_set<char>st;

        string s;

        cin>>s;

        st.insert(s[0]);
        st.insert(s[1]);

        cin>>s;

        st.insert(s[0]);
        st.insert(s[1]);

        if(st.size() == 4)
        {
            cout<<"3\n";
        }
        else if(st.size() == 3)
        {
            cout<<"2\n";
        }
        else if(st.size() == 2)
        {
            cout<<"1\n";
        }
        else if(st.size() == 1)
        {
            cout<<"0\n";
        }
    }
}