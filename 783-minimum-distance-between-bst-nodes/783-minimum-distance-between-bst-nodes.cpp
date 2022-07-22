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
    int mini = 1e8;
    int last = 1e8;
    void tr(TreeNode* root){
        if(root->left){
            tr(root->left);
        }
        mini = min(mini, abs(last - root->val));
        last = root->val;
        if(root->right){
            tr(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        tr(root);
        return mini;
    }
};