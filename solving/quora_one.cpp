#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;

    string s;

    cin>>s;

    int bonds = 0;
    int k = 1;
    string left ="";
    int mk = 1;

    while(k<n)
    {
        left.push_back(s[k-1]);

        j = left.length() - 1;
        int p = k;
        int b =0;
        while(j>=0 && p<n)
        {
            if((s[p] == 'A' && left[j] == 'T') || (s[p] == 'T' && left[j] == 'A') || (s[p]=='G' && left[j] == 'C') || (s[p] == 'C' && left[j] == 'G'))
            {
                b++;
            }

            j--;
            p++;
        }

        if(b>bonds)
        {
            bonds = b;
            mk = k;
        }

        k++;
    }

    cout<<mk<<" "<<bonds<<"\n";
}