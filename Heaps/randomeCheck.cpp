#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{

    vector<vector<int>> ans;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;

    for (auto p : points)
    {
        int dist = p[0] * p[0] + p[1] * p[1];

        if (pq.size() < k)
        {
            pq.push({dist, {p[0], p[1]}});
        }
        else if (dist < pq.top().first)
        {
            pq.pop();
            pq.push({dist, {p[0], p[1]}});
        }
    }

    while (!pq.empty())
    {
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    return ans;
}

int main()
{   
    cout<<"Enter the num points : ";
    int n;
    cin>>n;

    vector<vector<int> >pts;

    cout<<"Enter the points : \n";

    for(int i = 0 ; i < n ; i++)
    {
        int x,y;
        cin>>x>>y;
        pts.push_back({x,y});
    }

    cout<<"\n\nEnter the K : ";
    int k;
    cin>>k;

    auto ans = kClosest(pts,k);

    cout<<"\n\nClosests points are : \n";

    for(auto p : ans)
    {
        cout<<p[0]<<" , "<<p[1]<<"\n";
    }
}