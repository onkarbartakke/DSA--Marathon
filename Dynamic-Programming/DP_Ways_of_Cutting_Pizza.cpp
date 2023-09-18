#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007


/*
Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 

For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.

Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.


*/
class Solution
{
public:
    vector<string> pz;
    ll g[55][55];
    ll dp[55][55][55];
    int n, m;

    int solve(int r, int c, int cuts)
    {
        if (dp[r][c][cuts] != -1)
            return dp[r][c][cuts];

        if (cuts == 0)
        {
            if (g[r][c] > 0)
                dp[r][c][cuts] = 1;
            else
                dp[r][c][cuts] = 0;

            return dp[r][c][cuts];
        }

        // Horizontal Cuts

        dp[r][c][cuts] = 0;

        for (int i = r + 1; i < n; i++)
        {
            if (g[r][c] - g[i][c] > 0 && g[i][c] >= cuts)
            {
                dp[r][c][cuts] = (dp[r][c][cuts] + solve(i, c, cuts - 1)) % mod;
            }
        }

        // Vertical Cuts

        for (int j = c + 1; j < m; j++)
        {
            if (g[r][c] - g[r][j] > 0 && g[r][j] >= cuts)
            {
                dp[r][c][cuts] = (dp[r][c][cuts] + solve(r, j, cuts - 1)) % mod;
            }
        }

        return dp[r][c][cuts];
    }
    int ways(vector<string> &pizza, int k)
    {
        int ans = 0;

        this->pz = pizza;
        n = pizza.size();
        m = pizza[0].length();

        memset(g, 0, sizeof(g));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                g[i][j] = g[i][j + 1];

                for (int l = i; l < n; l++)
                {
                    g[i][j] += (pizza[l][j] == 'A');
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, k - 1);
    }
};


//https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/solutions/623759/c-dp-cutting-with-picture-explanation/

/*
This is a DP problem. Let n, m denote the rows and columns of the matrix, mat denote the matrix, f[r][c][l] denote the number of ways to cut mat[r..n-1][c..m-1] into l pieces so that each piece has at least one apple on them, g[r][c] denote the number of apples on mat[r..n-1][c..m-1]. Because after cutting, we always have the down-right corner of the matrix left, so this setting is valid.

For mat[r..n-1][c..m-1], we can cut the matrix in two directions in a number of ways, as long as the piece that is cut off has at least one apple on it. So

f[r][c][l] = 
    sum(f[i][c][l-1]) (i=r+1...n-1, g[r][c]-g[i][c]>0) +
    sum(f[r][j][l-1]) (j=c+1...m-1, g[r][c]-g[r][j]>0)
The time complexity is O(n * m * max(n, m) * k).

*/
int main()
{
}