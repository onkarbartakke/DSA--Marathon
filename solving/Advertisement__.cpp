#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);


    ll n;

    cin>>n;

    vector<ll>arr(n+1);

    for(int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    arr[n] = 0;

    stack<ll>st;

    ll maxArea = 0;

    ll w,h;

    for(int i = 0 ; i <= n ; i++)
    {
       // cout<<i<<" -->> "<<arr[i]<<"\n";



        if(st.empty() || arr[st.top()] <= arr[i])
        {
            st.push(i);
        }
        else
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                h = arr[st.top()];
                st.pop();

                if(st.empty())
                w = i;
                else
                w = i - st.top() - 1;

                maxArea = max(maxArea,h*w);

               // cout<<h<<" - "<<w<<"\n";
            }

            st.push(i);
        }
    }

    cout<<maxArea;
}

//  stack<int>st;
//     int i,j;
//     Hist.push_back(0);
//     n=Hist.size();
//     int area=0;
//     while(i<n)
//     {
//         if(st.empty() || Hist[st.top()]<=Hist[i])
//         {
//             st.push(i);
//             i++;
//         }
//         else
//         {
//             int tp=st.top();
//             st.pop();
//             int h=Hist[tp];
//             int w = (st.empty()) ? i : i - st.top() - 1;
//             area=max(area, h*(w));
//         }
//     }
    