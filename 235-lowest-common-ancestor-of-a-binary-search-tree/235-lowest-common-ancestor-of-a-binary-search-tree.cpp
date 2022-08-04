/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* left = NULL, * right = NULL;
        if(root->left)
            left = lowestCommonAncestor(root->left, p, q);
        if(root->right)
            right = lowestCommonAncestor(root->right, p, q);
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        if(left && right){
            return root;
        }
        return left?left:right;
    }
};