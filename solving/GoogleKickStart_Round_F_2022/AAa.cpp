#include<bits/stdc++.h>
#define ll long long
using namespace std;

class fabric
{
    public:

    string c;
    int d;
    int id;
    int i;
    fabric(string s, int du, int idd, int ii)
    {
        c = s;
        d = du;
        id = idd;
        i = ii;
    }
};

bool static comp1(fabric &f1 , fabric &f2)
{
    if((f1.c).compare(f2.c) == 0)
    return f1.id < f2.id;

    if((f1.c).compare(f2.c) < 0)
    return true;
    else
    return false;
}


bool static comp2(fabric &f1, fabric &f2)
{
    if(f1.d == f2.d)
    return f1.id < f2.id;

    return f1.d < f2.d;
}

int main()
{
    int t;

    cin>>t;
     int count = 1;
    while(t--)
    {

        int n;
        cin>>n;

        vector<fabric>a,b;

        for(int i = 0 ; i < n ; i++)
        {
            string s;
            cin>>s;
            int du;
            cin>>du;

            int id;
            cin>>id;

            fabric fa(s,du,id,i);

            a.push_back(fa);
            b.push_back(fa);

        }

        sort(a.begin() , a.end() , comp1);

        sort(b.begin(), b.end() , comp2);

        int ans = 0;

        for(int j = 0 ; j < n ; j++)
        {
            if(a[j].i == b[j].i )
            ans++;
        }


        cout<<"Case #"<<count<<": "<<ans<<"\n";
        count++;
    }

}