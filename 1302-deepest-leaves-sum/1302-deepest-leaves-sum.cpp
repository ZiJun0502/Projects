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
class Solution {
public:
    int maxi, sums;
    void find(TreeNode* node, int depth)
    {
        if(!node) return;
        if(depth > maxi)
        {
            maxi = depth;
        }
        find(node->right, depth + 1);
        find(node->left, depth + 1);
    }
    void sumTree(TreeNode* node, int depth)
    {
        if(!node) return;
        if(depth == maxi) sums+= node->val;
        sumTree(node->left,depth + 1);
        sumTree(node->right,depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        find(root, 0);
        sumTree(root, 0);
        return sums;
    }
};