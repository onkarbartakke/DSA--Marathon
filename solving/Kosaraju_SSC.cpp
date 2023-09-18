#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Transpose(vector<vector<int>> &adj)
{
    int v = adj.size();

    vector<vector<int>> tp(v);

    for (int i = 0; i < v; i++)
    {
        vector<int> v = adj[i];

        for (auto it : v)
        {
            tp[it].push_back(i);
        }
    }

    return tp;
}

void DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
            DFS(v, adj, vis, st);
    }

    st.push(u);
    return;
}

void DFS1(int u, vector<vector<int>> &adj, vector<int> &v, vector<bool> &vis)
{
    vis[u] = true;
    v.push_back(u);

    for (auto ve : adj[u])
    {
        if (!vis[ve])
            DFS1(ve, adj, v, vis);
    }
}

vector<vector<int>> Kosaraju(vector<vector<int>> adj)
{
    int n = adj.size();

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, st);
    }

    vector<vector<int>> tp = Transpose(adj);

    vector<vector<int>> ans;

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        if (!visited[curr])
        {
            vector<int> comp;
            DFS1(curr, tp, comp, visited);
            ans.push_back(comp);
        }
    }

    return ans;
}



void DFS(int u, vector<int>adj[], vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
            DFS(v, adj, vis, st);
    }

    st.push(u);
    return;
}


vector<vector<int>> Transpose(vector<int>adj[] , int V)
{
   

    vector<vector<int>> tp(V);

    for(int i = 0 ; i < V ; i++)
    {
        for(auto uu : adj[i])
        {
            tp[uu].push_back(i);   
        }
    }


    return tp;
}


void DFS1(int u, vector<vector<int>> &adj, vector<int> &v, vector<bool> &vis)
{
    vis[u] = true;
    v.push_back(u);

    for (auto ve : adj[u])
    {
        if (!vis[ve])
            DFS1(ve, adj, v, vis);
    }
}


int kosaraju(int V, vector<int> adj[])
{
    // code here
    int n = V;

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(i, adj, visited, st);
    }

    vector<vector<int>> tp = Transpose(adj,V);

    vector<vector<int>> ans;

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        if (!visited[curr])
        {
            vector<int> comp;
            DFS1(curr, tp, comp, visited);
            ans.push_back(comp);
        }
    }

    return ans.size();
}
int main()
{
}