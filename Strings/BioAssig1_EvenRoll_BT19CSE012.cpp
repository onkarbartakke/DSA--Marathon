#include<bits/stdc++.h>

using namespace std;

/*

NAME : ONKAR SUHAS BARTAKKE
ENROLL : BT19CSE012

EVEN ROLL

BIOINFO ASSIGNMENT 1


B. Dump in a file all the unique stings that can be obtained from one
string by changing k numbers of add/modify/delete.

Example: Original String = AA and K=1

There are 17 Number of strings possible:

AAA
CAA  ACA  AAC
GAA  AGA  AAG
TAA   ATA   AAT

CA   AC
GA  AG
TA   AT

A

*/

// A C G T
char chrs[] = {'A' , 'C' , 'G' , 'T'};


void solve(string s, unordered_set<string>&st, int k)
{
    if(k <= 0)
    {
        st.insert(s);
        return;
    }

    k--;
    //Add

    string left = "" , right = s;

    for(int i = 0 ; i < s.length() ; i++)
    {
        left = s.substr(0,i);
        right = s.substr(i);

    
        for(int j = 0 ; j < 4 ; j++)
        {
            left.push_back(chrs[j]);
            string str = left+right;
        
            solve(str,st,k);
            left.pop_back();
        }
    }

    left = s;
    for(int j = 0 ; j < 4 ; j++)
    {
        left.push_back(chrs[j]);
        solve(left,st,k);
        left.pop_back();
    }


    // Update

    for(int i = 0 ; i < s.length() ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(s[i] != chrs[j])
            {
                char temp = s[i];
                s[i] = chrs[j];
                solve(s,st,k);
                s[i] = temp;
            }
        }
    }


    // Delete

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(i > 0)
        left = s.substr(0,i);
        else
        left = "";

        if(i < s.length() - 1)
        right = s.substr(i+1);
        else
        right = "";

        solve(left+right,st,k);
    }
}



int main()
{
    ofstream f("output_BT19CSE012.txt");
    cout<<"Enter the String : ";
    string s;

    cin>>s;

    int n = s.length();

    int k;
    cout<<"\n\nEnter the K : ";
    cin>>k;

    unordered_set<string>st;

    solve(s,st,k);

    f << st.size()<<"\n\n";

    for(auto &str : st)
    {
        f<<str<<"\n";
    }

}