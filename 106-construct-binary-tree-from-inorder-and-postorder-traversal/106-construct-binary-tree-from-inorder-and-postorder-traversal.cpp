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
    void re(vector<int> in, vector<int> po, int inl, int inr, int prel, int prer,
            TreeNode* now){
        int i;
        if(inl >= inr) return;
         //cout << inl <<' ' <<inr<<'\n';
         //cout << prel <<' ' <<prer<<'\n';
        for(i = inl; i <= inr ; i++){
            if(in[i] == now->val) break;
        }
        //cout << i <<'\n';
        if(i-inl > 0){
            now->left = new TreeNode(po[prel + i - inl - 1]);
            re(in, po, inl, i-1, prel, prel+i-1-inl, now->left);
        }else now->left = NULL;
        if(inr-i > 0){
            now->right = new TreeNode(po[prer-1]);
            re(in, po, i+1, inr, prel+i-inl, prer-1, now->right);
        }else now->right = NULL;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        re(inorder, postorder, 0, n-1, 0, n-1, root);
        return root;
    }
};