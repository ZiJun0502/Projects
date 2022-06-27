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
    void help(TreeNode* root, int num)
    {
        if(!root->left && !root->right)
            ans += num;
        if(root->left) help(root->left, num*10 + root->left->val);
        if(root->right) help(root->right, num*10 + root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        help(root, root->val);
        return ans;
    }
};