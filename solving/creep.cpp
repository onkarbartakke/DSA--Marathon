#include<bits/stdc++.h>

using namespace std;
bool possible(int creep , int a, int b, string &s)
{
    if(a > b)
    {
        while(a && b)
        {
            int crep = creep;

            while(crep)
            {
                crep--;
                s += "0";
                a--;

                if(a == 0)
                break;
            }

            crep = creep;

            while(crep)
            {
                crep--;
                s += "1";
                b--;

                if(b == 0)
                break;
            }
        }

        if(a > creep || b > creep)
        return false;

        while(a)
        {
            s += "0";
            a--;
        }

        while(b)
        {
            s+= "1";
            b--;
        }
    }
    else
    {
        while(a && b)
        {
            int crep = creep;

            while(crep)
            {
                crep--;
                s += "1";
                b--;

                if(b == 0)
                break;
            }

            crep = creep;

            while(crep)
            {
                crep--;
                s += "0";
                a--;

                if(a == 0)
                break;
            }
        }

        if(a > creep || b > creep)
        return false;

        while(a)
        {
            s += "0";
            a--;
        }

        while(b)
        {
            s+= "1";
            b--;
        }
    }

    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        // a 0
        // b 1

        cin>>a>>b; 

        int l = 1, h = max(a,b);

        int mid = (l+h)/2;

        string ans = "";
        while(l<=h)
        {
            mid = (l+h)/2;

            string s;
            if(possible(mid,a,b,s))
            {
                ans = s;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout<<ans<<"\n";
    }
}