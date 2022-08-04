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
    vector<int> in, po;
    void re(int inl, int inr, int prel, int prer, TreeNode* now){
        if(inl >= inr) return;
        int i;
        for(i = inl; i <= inr ; i++){
            if(in[i] == now->val) break;
        }
        if(i-inl > 0){
            now->left = new TreeNode(po[prel + i - inl - 1]);
            re(inl, i-1, prel, prel+i-1-inl, now->left);
        }else now->left = NULL;
        if(inr-i > 0){
            now->right = new TreeNode(po[prer-1]);
            re(i+1, inr, prel+i-inl, prer-1, now->right);
        }else now->right = NULL;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        in = inorder, po = postorder;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        re(0, n-1, 0, n-1, root);
        return root;
    }
};