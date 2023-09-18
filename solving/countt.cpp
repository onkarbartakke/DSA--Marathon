#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int solve(int i, int j, vector<vector<char>> &mat, string target, int n, int idx)
    {

        int count = 0;

        // these are the boundary conditions

        // see it like this we take starting position of string say idx and mat[i][j] is the starting pos of mat

        // compare both of them, if we found a char we will store it and we will update that char with 0 to avoid looping

        // now move forward and update idx.. if our idx reaches end of string means we have found out the word and increase the counter n return that

        // else search in all four directions.

        if (i >= 0 && j >= 0 && i < mat.size() && j < mat[0].size() && target[idx] == mat[i][j])
        {

            char temp = target[idx];

            mat[i][j] = 0;

            idx += 1;

            if (idx == n)
            {

                count = 1;
            }

            else
            {

                count += solve(i + 1, j, mat, target, n, idx);

                count += solve(i - 1, j, mat, target, n, idx);

                count += solve(i, j + 1, mat, target, n, idx);

                count += solve(i, j - 1, mat, target, n, idx);
            }

            // why we are back tracking here is to search all the possible counters of a word..
            // If we don't, the counter will always be one..

            mat[i][j] = temp; // backtrack
        }

        return count;
    }

    int findOccurrence(vector<vector<char>> &mat, string target)
    {

        // this can be understood easily

        int ans = 0;

        int n = target.size();

        for (int i = 0; i < mat.size(); i++)
        {

            for (int j = 0; j < mat[0].size(); j++)
            {

                ans += solve(i, j, mat, target, n, 0);
            }
        }

        return ans;
    }
};

vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries)
{
    // Code here
    vector<vector<int>> grid(n, vector<int>(n));

    for (auto e : Queries)
    {
        int a = e[0], b = e[1];
        int c = e[2], d = e[3];

        grid[a][b]++;
        if (d + 1 < n)
            grid[a][d + 1]--;
        if (c + 1 < n)
            grid[c + 1][b]--;
        if (c + 1 < n and d + 1 < n)
            grid[c + 1][d + 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
                grid[i][j] += grid[i - 1][j];
            if (j > 0)
                grid[i][j] += grid[i][j - 1];
            if (i > 0 and j > 0)
                grid[i][j] -= grid[i - 1][j - 1];
        }
    }

    return grid;
}