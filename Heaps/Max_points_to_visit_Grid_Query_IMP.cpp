#include <bits/stdc++.h>

using namespace std;

/*
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queres[i] you start in the top
 left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you
get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all
 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you
are allowed to visit the same cell multiple times.

Return the resulting array answer.

 */
class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &q)
    {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<int> path;

        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<vector<int>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();

            int val = abs(v[0]);
            path.push_back(val);

            int x = v[1], y = v[2];

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == false)
                {
                    pq.push({-grid[nx][ny], nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }

        vector<int> ans(q.size());

        vector<pair<int, int>> sortQ;

        for (int i = 0; i < q.size(); i++)
        {
            sortQ.push_back({q[i], i});
        }

        sort(sortQ.begin(), sortQ.end());

        int count = 0;
        int j = 0;
        for (int i = 0; i < path.size();)
        {
            if (sortQ[j].first > path[i])
            {
                count++;
                // if(i == path.size() - 1)
                // {

                // }
                i++;
            }
            else
            {
                ans[sortQ[j].second] = count;
                j++;
            }

            if (j >= sortQ.size())
                break;
        }

        while (j < sortQ.size())
        {
            ans[sortQ[j].second] = count;
            j++;
        }

        return ans;
    }
};

/*
Intuition
So we want to get the max score ,it would be helpful if we in some way choose smaller values when we have option .
Looking at the problems we know we have to do traversal using bfs or dfs and that too greedily.

Approach
We will find the best path greedily prioritising the smaller values using min heap,we will use min heap
for doing bfs traversal .
Once we get out path we will get copy of queries and sort them in increasing order,
we start from 1st value and check if we can go through our path and increment our count ,
if we can't we go to next value of sorted query and so on.*/

// Approach 2 - Rank Union method
/*
Intuition
Assume that there is just a single query, how would you solve this problem?
Thats easy, you would start a dfs/bfs from the top left cell and keep exploring the neighbours until the value is strictly lesser than the given query value.
The above task is achievable in linear time with respect to the number of cells because we visit each cell exactly once, how can you maintain this when we have multiple queries?
We sort the queries! If we visit a group of cells for a query value Q, we can visit the same set of cells perhaps more for any query value Q' which is greater than Q
Approach
Process the queries from small to large. Add nodes to the graph such that their value is less than the current query.
Whenever a new node is added, add the corresponding edges in the graph.
Note: each cell is represented in a 1-D format (Row major order)
Rest of it must be clear if you know Union find.*/

class Solution1
{
public:
    // UNION FIND
    vector<int> par, rank;
    int find(int a)
    {
        if (par[a] == -1)
            return a;
        return par[a] = find(par[a]);
    }
    void uni(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;
        par[b] = a;
        rank[a] += rank[b];
    }
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size(), m = grid[0].size();
        par = vector<int>(n * m + m, -1);
        rank = vector<int>(n * m + m, 1);
        vector<vector<int>> nodes;
        // sort the nodes
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                nodes.push_back({grid[i][j], i, j});
            }
        }
        sort(nodes.begin(), nodes.end());
        // sort the queries
        vector<vector<int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++)
        {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> ans(queries.size()), visited(n * m + m);
        int index = 0;
        vector<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
        for (auto &q : sortedQueries)
        {
            // add nodes to graph
            while (index < n * m and nodes[index][0] < q[0])
            {
                int x = nodes[index][1], y = nodes[index][2];
                visited[x * m + y] = 1;
                // add edges
                for (int z = 0; z < 4; z++)
                {
                    int X = x + dx[z], Y = y + dy[z];
                    if (X >= 0 and Y >= 0 and X < n and Y < m and visited[X * m + Y])
                    {
                        uni(X * m + Y, x * m + y);
                    }
                }
                index++;
            }
            if (visited[0])
                ans[q[1]] = rank[find(0)];
        }
        return ans;
    }
};

