/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include <headers.h>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;

        if (root == NULL)
        {
            return res;
        }

        string ans;
        dfs(root, ans, res);
        return res;
    }

    void dfs(TreeNode *root, string curr, vector<string> &res)
    {
        if (root == nullptr)
        {
            return;
        }

        curr += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            res.push_back(curr);
        }
        dfs(root->left, curr + "->", res);

        dfs(root->right, curr + "->", res);
    }
};
// @lc code=end
