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
    void con(TreeNode* root, int &last){
        if(root->right){
            con(root->right, last);
        }
        last += root->val;
        root->val = last;
        if(root->left){
            con(root->left, last);    
        }
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        int last = 0;
        con(root, last);
        return root;
    }
};