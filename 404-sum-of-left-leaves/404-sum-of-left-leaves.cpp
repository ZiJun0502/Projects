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
    int ans;
    int sumOfLeftLeaves(TreeNode* root, int flag = 0) {
        if(!root) return 0;
        sumOfLeftLeaves(root->left, 1);
        if(!root->right && !root->left && flag) ans+=root->val;
        sumOfLeftLeaves(root->right, 0);
        
        return ans;
    }
};