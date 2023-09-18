#include <bits/stdc++.h>

using namespace std;
/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
class Solution
{
public:
    bool search(int pos, string &word, vector<vector<bool>> &vis, unordered_map<char, vector<pair<int, int>>> &mp, int r, int c)
    {
        if (pos >= word.length())
            return true;

        auto v = mp[word[pos]];

        for (auto p : v)
        {
            int i = p.first;
            int j = p.second;

            if (vis[i][j] == true)
                continue;

            if ((abs(r - i) == 1 && abs(c - j) == 0) || (abs(r - i) == 0 && abs(c - j) == 1))
            {
                vis[i][j] = true;
                if (search(pos + 1, word, vis, mp, i, j))
                    return true;

                vis[i][j] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        unordered_map<char, vector<pair<int, int>>> mp;

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mp[board[i][j]].push_back({i, j});
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        char ch = word[0];

        auto v = mp[ch];

        for (auto p : v)
        {
            int r = p.first;
            int c = p.second;

            vis[r][c] = true;

            if (search(1, word, vis, mp, r, c))
                return true;

            vis[r][c] = false;
        }

        return false;
    }
};