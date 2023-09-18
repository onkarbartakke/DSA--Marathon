#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ll long long
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

/*
You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:

0 represents grass,
1 represents fire,
2 represents a wall that you and fire cannot pass through.
You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.

Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.

Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.

A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

*/


bool possible(vector<vector<int>> &grid, vector<vector<int>> &fire, ll waitTime)
{
    queue<vector<int>> qu;
    int m = grid.size(), n = grid[0].size();
    int wt = (int)waitTime;

    if (wt == 0)
        cout << "\nWt is zero\n";

    qu.push({0, 0, wt});

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    vis[0][0] = true;

    while (!qu.empty())
    {
        auto v = qu.front();
        qu.pop();

        int x = v[0], y = v[1], ti = v[2];

        if (wt == 0 && x == m - 1 && y == n - 1)
        {
            cout << "\n\n**\n\n"
                 << ti << "  - " << fire[x][y] << "\n\n";
        }
        if (x == m - 1 && y == n - 1 && ti <= fire[x][y])
        {
            return true;
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                {
                    if (!vis[nx][ny] && grid[nx][ny] == 0 && fire[nx][ny] >= 1 + ti)
                    {
                        qu.push({nx, ny, 1 + ti});
                        vis[nx][ny] = true;
                    }

                    if(nx == m - 1 && ny == n-1 && grid[nx][ny] == 0  && fire[nx][ny] >= 1 + ti)
                    return true;
                }
            }
        }
    }

    return false;
}
int maximumMinutes(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> fire(m, vector<int>(n, INT_MAX));

    queue<pair<int, int>> qu;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                qu.push({i, j});
                fire[i][j] = 0;
            }
        }
    }

    while (!qu.empty())
    {
        auto p = qu.front();
        qu.pop();

        int x = p.first;
        int y = p.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0 && fire[nx][ny] == INT_MAX)
            {
                fire[nx][ny] = 1 + fire[x][y];
                qu.push({nx, ny});
            }
        }
    }

    cout<<"\nFire Matrix is : \n";

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        cout<<fire[i][j]<<" ";


        cout<<"\n";
    }
    ll low = 0, high = INF, mid;
    int ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        cout << low << " " << mid << " " << high << "\n";
        if (possible(grid, fire, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}


int main()
{
    int m,n;

    cin>>m>>n;

    vector<vector<int>>grid(m , vector<int>(n));

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin>>grid[i][j];
        }
    }

    int ans = maximumMinutes(grid);
    cout<<"\n\nans : "<<ans<<"\n";
}

//https://leetcode.com/problems/escape-the-spreading-fire/description/

//https://leetcode.com/problems/escape-the-spreading-fire/solutions/1995157/solution-intuition-explanation-with-pictures/