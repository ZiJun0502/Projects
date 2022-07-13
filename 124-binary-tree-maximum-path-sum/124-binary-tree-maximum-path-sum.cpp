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
    int maxiPath = -1e9;
    int re(TreeNode* root){
        if(!root) return 0;
        int l = max(0, re(root->left));
        int r = max(0, re(root->right));
        //after calculating the height of l and r child, calculate the maximum path.
        maxiPath = max(maxiPath, l + r + root->val);
        return root->val + max(l, r); // maximum height of root
    }
    int maxPathSum(TreeNode* root) {
        re(root);
        return maxiPath;
    }
};