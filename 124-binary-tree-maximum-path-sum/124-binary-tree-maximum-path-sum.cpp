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
    int re(TreeNode* root, int& maxiPath){
        if(!root) return 0;
        int l = max(0, re(root->left, maxiPath));
        int r = max(0, re(root->right, maxiPath));
        //after calculating the height of l and r child, calculate the maximum path.
        maxiPath = max(maxiPath, l + r + root->val);
        return root->val + max(l, r); // maximum height of root
    }
    int maxPathSum(TreeNode* root) {
        int i = -1e9;
        re(root, i);
        return i;
    }
};