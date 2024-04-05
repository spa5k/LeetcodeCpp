/*
 * @lc app=leetcode id=1676 lang=cpp
 *
 * [1676] Lowest common ancestor of a binary tree IV
 */
#include <headers.h>

// @lc code=start
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Definition for a binary tree node.

class Solution
{
public:
    // Function to find the lowest common ancestor of a set of nodes in a binary tree
    TreeNode *lowestCommonAncestor(TreeNode *root, vector<TreeNode *> &nodes)
    {
        // Check if the root is null, if so, return null
        if (!root)
        {
            return nullptr;
        }

        // Check if the root itself is one of the target nodes
        if (isNodeInList(root, nodes))
        {
            // If the root is one of the target nodes, return it
            return root;
        }

        // Check the left subtree for the lowest common ancestor
        TreeNode *leftLCA = lowestCommonAncestor(root->left, nodes);
        // Check the right subtree for the lowest common ancestor
        TreeNode *rightLCA = lowestCommonAncestor(root->right, nodes);

        // If one of the subtrees contains the lowest common ancestor, return it
        if (leftLCA && rightLCA)
        {
            return root;
        }

        // If leftLCA is not null, return it, otherwise, return rightLCA
        return leftLCA ? leftLCA : rightLCA;
    }

    // Function to check if a given node is in the list of nodes
    bool isNodeInList(TreeNode *node, vector<TreeNode *> &nodes)
    {
        // Iterate through the list of nodes
        for (TreeNode *n : nodes)
        {
            // If the current node matches any node in the list, return true
            if (node == n)
            {
                return true;
            }
        }
        // If the node is not found in the list, return false
        return false;
    }
};
// @lc code=end
