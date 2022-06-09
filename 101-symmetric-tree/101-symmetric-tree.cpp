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
    bool re(TreeNode* l, TreeNode* r)
    {
        if(!r || !l) return r == l;
        else if(r->val != l->val)
            return false;
        return re(l->left, r->right) && re(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return re(root->left, root->right);
    }
};