#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, sx, sy, d;

        cin >> n >> m >> sx >> sy >> d;

        // vector<vector<int>> grid(n + 1, vector<int>(m + 1, -1));

        // grid[sx][sy] = -2;
        // grid[1][1] = 0;

        // queue<pair<int, int>> qu;
        // qu.push({1, 1});
        // bool reached  = false;

        // while (!qu.empty())
        // {
        //     auto p = qu.front();
        //     qu.pop();

        //     int nx, ny;

        //     for (int i = 0; i < 4; i++)
        //     {
        //         nx = p.first + dx[i];
        //         ny = p.second + dy[i];

        //         if(nx>=1 && ny>=1 && nx <= n && ny<=m)
        //         {
        //             if(abs(nx-sx) + abs(ny-sy) <= d || grid[nx][ny]!=-1)
        //             continue;
        //             else if(grid[nx][ny] == -1)
        //             {
        //                 grid[nx][ny] = 1 + grid[p.first][p.second];
        //                 qu.push({nx,ny});

        //                 if(nx == n && ny == m)
        //                 {
        //                     reached  = true;
        //                     cout<<grid[nx][ny]<<"\n";
        //                     break;
        //                 }
        //             }
        //         }
        //     }

        //     if(reached)
        //     break;
        // }

        // if(!reached)
        // cout<<"-1\n";


        if(abs(sx-n) + abs(sy-m) <= d)
        {
            cout<<"-1\n";
        }
        else if(abs(sx-1) + abs(sy-2) <= d && abs(sx-2) + abs(sy-1) <= d)
        {
            cout<<"-1\n";
        }
        else if(abs(sx-1)<=d && abs(sx-n)<=d)
        {
            cout<<"-1\n";
        }
        else if(abs(sy-1)<=d && abs(sy-m)<=d)
        {
            cout<<"-1\n";
        }
        else if(abs(sx-n)<=d && abs(sy-m)<=d)
        {
            cout<<"-1\n";
        }
        else if(abs(sx-1)<=d && abs(sy-1)<=d)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<(n+m-2)<<"\n";
        }
    }
}