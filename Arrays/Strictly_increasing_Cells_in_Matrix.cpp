#include<bits/stdc++.h>

using namespace std;

/*
Given a 1-indexed m x n integer matrix mat, you can select any cell in the matrix as your starting cell.

From the starting cell, you can move to any other cell in the same row or column, but only if the value of the destination cell is strictly greater than the value of the current cell. You can repeat this process as many times as possible, moving from cell to cell until you can no longer make any moves.

Your task is to find the maximum number of cells that you can visit in the matrix by starting from some cell.

Return an integer denoting the maximum number of cells that can be visited.
*/
class Solution
{
public:
    int maxIncreasingCells(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        map<int, vector<vector<int>>> mp;

        vector<int> r(m, 0), c(n, 0);

        vector<vector<int>> temp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[-mat[i][j]].push_back({i, j});
            }
        }

        for (auto it : mp)
        {
            int ele = -it.first;
            auto &v = it.second;

            for (auto &pos : v)
            {
                temp[pos[0]][pos[1]] = max(r[pos[0]], c[pos[1]]) + 1;
            }

            for (auto &pos : v)
            {
                r[pos[0]] = max(r[pos[0]], temp[pos[0]][pos[1]]);
                c[pos[1]] = max(c[pos[1]], temp[pos[0]][pos[1]]);
            }
        }

        return max(*max_element(r.begin(), r.end()), *max_element(c.begin(), c.end()));
    }
};

//https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/solutions/3570203/longest-path-in-c-java-python/