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
    void re(TreeNode* root){
        swap(root->left, root->right);
        if(root->left) re(root->left);
        if(root->right) re(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        re(root);
        return root;
    }
};
