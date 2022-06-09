class Solution {
public:
    bool re(TreeNode* l,TreeNode* r)
    {
        if(l && !r || r && !l) return false;
        if(l==NULL && r==NULL) return true;
        if(l->val != r->val) return false;
        return re(l->left, r->right) && re(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        return re(root->left,root->right);
    }
};