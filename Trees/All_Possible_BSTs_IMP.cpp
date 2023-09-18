#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.

/*Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//https://leetcode.com/problems/unique-binary-search-trees-ii/description/
class Solution
{
public:
    vector<TreeNode *> generateSubTrees(int start, int end)
    {
        vector<TreeNode *> ret;

        if (start > end)
        {
            ret.push_back(NULL);
            return ret;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftSubTree = generateSubTrees(start, i - 1);
            vector<TreeNode *> rightSubTree = generateSubTrees(i + 1, end);

            for (auto leftNode : leftSubTree)
            {
                for (auto rightNode : rightSubTree)
                {
                    TreeNode *r = new TreeNode(i);
                    r->left = leftNode;
                    r->right = rightNode;
                    ret.push_back(r);
                }
            }
        }

        return ret;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ans;

        if (n == 0)
            return ans;

        if (n == 1)
        {
            TreeNode *r = new TreeNode(1);
            ans.push_back(r);
            return ans;
        }

        return generateSubTrees(1, n);
    }
};