#include <bits/stdc++.h>

using namespace std;

vector<int> arr(200007);
vector<int> pos(2000007, -1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;

    cin >> n >> m;

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];

        pos[arr[i]] = i;

        if (pos[arr[i] - 1] == -1)
            cnt++;
    }

    int a, b;

    set<pair<int,int>>st;


    while (m--)
    {
        cin >> a >> b;

        if(arr[a] - 1 >= 1)
        st.insert({arr[a] - 1 , arr[a]});
        
        if(arr[a]+1 <= n)
        st.insert({arr[a] , arr[a]+1});

        if(arr[b] - 1 >= 1)
        st.insert({arr[b]-1,arr[b]});

        if(arr[b] <= n)
        st.insert({arr[b] , arr[b]+1});


        for(auto p : st)
        {
            cnt -= (pos[p.first] > pos[p.second]);
        }

        swap(arr[a] , arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;

        for(auto p : st)
        {
            cnt += (pos[p.first] > pos[p.second]);
        }

        cout<<cnt<<"\n";
        st.clear();
    }
}