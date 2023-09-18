#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

vector<vector<vector<int>>>dp(41, vector<vector<int>>(41, vector<int>(41,-1)));
int n,m;


int DFS(int i, int j, vector<vector<int>> &grid, int k)
{
    if (i == n - 1 && j == m - 1)
    {
        return dp[i][j][k] = 0;
    }

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    int temp = grid[i][j];
    grid[i][j] = -1;
    int mini = INT_MAX;
    int ret = INT_MAX;

    for (int t = 0; t < 4; t++)
    {
        int nx = i + dx[t];
        int ny = j + dy[t];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != -1)
        {

            if (grid[nx][ny] == 1 && k > 0)
            {
                ret = DFS(nx, ny, grid, k - 1);
            }
            else if (grid[nx][ny] == 0)
            {
                ret = DFS(nx, ny, grid, k);
            }

            if (ret != INT_MAX)
                ret++;

            mini = min(mini, ret);
        }
    }

    dp[i][j][k] = mini;
    grid[i][j] = temp;

    return mini;
}

int shortestPath(vector<vector<int>> &grid, int k)
{

    n = grid.size(), m = grid[0].size();
    int ans = DFS(0, 0, grid, k);

    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}



int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int>>grid(r, vector<int>(c));

    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        cin>>grid[i][j];
    }

    int k;
    cin>>k;

    cout<<"\n\n"<<shortestPath(grid,k);
}