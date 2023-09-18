#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n,x,y;

        cin>>n>>x>>y;

        if(x<=y)
        {
            int b = n/100;
            if(n%100!=0)
            b++;

            cout<<b*x;
        }
        else
        {
            if(y*25 <=x)
            {
                int c = n/4;
                if(n%4!=0)
                c++;
                cout<<c*y;
            }
            else
            {
                int bc = 0;

                int bus = (n/100);
                int r = n%100;
                int car = r/4;

                if(r%4 != 0)
                car++;

                if(x<= y*car)
                {
                    bus++;
                    cout<<bus*x;
                }
                else
                {
                    cout<<bus*x+car*y;
                }

            }
        }

        cout<<"\n";
    }
}