#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int oddCount;
    unordered_set<int>odd;
    //unordered_set<int>even;

    Node(int o = 0)
    {
        oddCount = o;
    }

    void Merge(Node &left, Node &right)
    {
        odd.clear();
        for(auto it : left.odd)
        {
            if(right.odd.find(it) == right.odd.end())
            {
                odd.insert(it);
            }
        }

        for(auto it : right.odd)
        {
            if(left.odd.find(it) == left.odd.end())
            {
                odd.insert(it);
            }
        }

        oddCount = odd.size();
    }
};


void Build(vector<Node>&seg, vector<int>&Arr, int ind, int low, int high)
{
    if(low == high)
    {
        seg[ind].oddCount = 1;
        seg[ind].odd.insert(Arr[low]);
        return;
    }

    int mid = (high+low)>>1;

    Build(seg,Arr,2*ind+1,low,mid);
    Build(seg,Arr,2*ind+2,mid+1,high);

    seg[ind].Merge(seg[2*ind+1] , seg[2*ind+2]);
}

void Update(vector<Node>&seg, int low, int high, int idx, int val,int ind)
{
    if(low == high)
    {
        seg[ind].oddCount = 1;
        seg[ind].odd.clear();
        seg[ind].odd.insert(val);
        return;
    }

    int mid = (low+high)>>1;

    if(idx <= mid)
    Update(seg,low,mid,idx,val,2*ind+1);
    else
    Update(seg,mid+1,high,idx,val,2*ind+2);


    seg[ind].Merge(seg[2*ind+1], seg[2*ind+2]);
}

Node Query(vector<Node>&seg,int l , int r, int low, int high, int ind)
{
    if(r<low || high < l)
    {
        Node n(0);
        return n;
    }

    if(l<=low && high <= r)
    return seg[ind];

    int mid = (low+high)>>1;

    Node left =  Query(seg,l,r,low,mid,2*ind+1);
    Node right = Query(seg,l,r,mid+1,high,2*ind+2);

    Node ret;

    for(auto it : left.odd)
    {
        if(right.odd.find(it) == right.odd.end())
        ret.odd.insert(it);
    }

    for(auto it : right.odd)
    {
        if(left.odd.find(it) == left.odd.end())
        ret.odd.insert(it);
    }

    return ret;
}

vector<int> solve(int N, int Q, vector<int>Arr , vector<vector<int>>queries)
{
    int n = N+1;

    vector<Node>seg(4*n);

    Build(seg,Arr,0,0,N-1);
    vector<int>ans;

    for(int i = 0 ; i < Q ; i++)
    {
        auto v = queries[i];

        if(v[0] == 1)
        {
            int idx = v[1]-1;
            int val = v[2];
            Arr[idx] = val;
            Update(seg,0,N-1,idx,val,0);    
        }
        else if(v[0] == 2)
        {
            int l = v[1]-1;
            int r = v[2]-1;
            Node cnt = Query(seg,l,r,0,N-1,0);
            ans.push_back(cnt.oddCount);
        }
    }

    return ans;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;

        vector<int>Arr(N);

        int Q;

        cin>>Q;

        vector<vector<int>>queries(Q, vector<int>(3));

        for(int i = 0 ; i<N ; i++)
        cin>>Arr[i];


        for(int i = 0 ; i < Q ; i++)
        {
            cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
        }

        vector<int>ans = solve(N,Q,Arr,queries);
        cout<<"\n\n****\n\n";
        for(auto it : ans)
        cout<<it<<" ";
    }

    cout<<"\n";
}