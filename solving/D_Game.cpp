#include<bits/stdc++.h>

using namespace std;


int solve(string s, int start)
{
    int chn = 0;


    for(int i = 0 ; i < s.length() ; i++)
    {
        if(i%2 == 0)
        {
            if(s[i] - '0' == start)
            continue;
            else
            {
                if(s[i] == s[i+1])
                {
                    
                }
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;

    string s;

    cin>>s;

    cout<<min(solve(s,1) , solve(s,0))<<"\n";
}