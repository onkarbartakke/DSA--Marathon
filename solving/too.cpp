#include<bits/stdc++.h>

using namespace std;


bool DFS(int r, int c, vector<vector<char>>&grid, int col)
{
    if(r<0 || c<0 || r>=grid.size() || c >= grid[0].size())
    return true;

   if((grid[r][c]=='R' && col == 0) || (grid[r][c] == 'W' && col == 1))
   {
       if(r+1 < grid.size())
       {
           if(grid[r+1][c] == '.')
           DFS(r+1,c,grid,!col);
           else if(grid[r][c] == grid[r+1][c])
           return false;
       }

       if(r-1 >= 0)
       {
           if(grid[r-1][c] == '.')
           DFS(r-1,c,grid,!col);
           else if(grid[r][c] == grid[r-1][c])
           return false;
       }


        if(c+1 < grid[0].size())
       {
           if(grid[r][c+1] == '.')
           DFS(r,c+1,grid,!col);
           else if(grid[r][c] == grid[r][c+1])
           return false;
       }

       if(c-1 >= 0)
       {
           if(grid[r][c-1] == '.')
           DFS(r,c-1,grid,!col);
           else if(grid[r][c] == grid[r][c-1])
           return false;
       }
   }


   if((grid[r][c]=='R' && col == 1) || (grid[r][c] == 'W' && col == 0))
   return false;

    if(grid[r][c] == '.')
    {
        grid[r][c] = (col == 1) ? 'W' : 'R';

        bool ps ;

        ps = DFS(r+1,c,grid,!col);

        if(!ps)
        return false;

        ps = DFS(r,c+1,grid,!col);

        if(!ps)
        return false;

        ps = DFS(r-1,c,grid,!col);

        if(!ps)
        return false;

        ps = DFS(r,c-1,grid,!col);

        if(!ps)
        return false;

        return true;
    }

    return true;    

}
bool possible(vector<vector<char>>&grid)
{
    int n = grid.size(), m = grid[0].size();
    bool ps ;

    bool alldots = true;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[i][j]!='.')
            {
                alldots = false;
                int col;
                if(grid[i][j] == 'W')
                col = 1;
                else
                col = 0;
                ps = DFS(i,j,grid,col);

                if(ps == false)
                return false;
            }
                
        }
    }
    int col = 1;
    int rowCol = 1;
    if(alldots)
    {
        for(int i = 0 ; i < n ; i++)
        {
            col = rowCol;
            for(int j = 0 ; j < m ; j++)
            {
                grid[i][j] = (col == 1) ? 'W' : 'R';

                col = !col;
            }

            rowCol = !rowCol;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;

        cin>>n>>m;

        vector<vector<char>>grid(n, vector<char>(m,'.'));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j <m ; j++)
            {
                cin>>grid[i][j];
            }
        }


        if(possible(grid))
        {
            cout<<"YES\n";

            for(int i = 0 ; i< n ; i++)
            {
                for(int j = 0 ; j < m; j++)
                {
                    cout<<grid[i][j];
                }
                cout<<"\n";
            }
        }
        else
        {
            cout<<"NO\n";
        }
    }
}