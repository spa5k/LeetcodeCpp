/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
    int deepestLeavesSum(TreeNode *root)
    {
        deque<TreeNode *> q;
        q.push_back(root);
        int total_sum = 0;

        while (!q.empty())
        {
            total_sum = 0;
            int level_size = q.size();
            for (int i = 0; i < level_size; i++)
            {
                TreeNode *node = q.front();
                q.pop_front();
                total_sum += node->val;
                if (node->left)
                {
                    q.push_back(node->left);
                }
                if (node->right)
                {
                    q.push_back(node->right);
                }
            }
        }

        return total_sum;
    }
};

// @lc code=end
