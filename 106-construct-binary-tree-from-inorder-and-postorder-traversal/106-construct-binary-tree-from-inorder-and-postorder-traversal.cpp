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
    TreeNode* re(int inl, int inr, int prel, int prer){
        int i;
        TreeNode* root = new TreeNode(po[prer]);
        if(inl >= inr) return root;
         //cout << inl <<' ' <<inr<<'\n';
         //cout << prel <<' ' <<prer<<'\n';
        for(i = inl; i <= inr ; i++){
            if(in[i] == root->val) break;
        }
        //cout << i <<'\n';
        if(i-inl > 0){
            root->left = re(inl, i-1, prel, prel+i-1-inl);
        }else root->left = NULL;
        if(inr-i > 0){
            root->right = re(i+1, inr, prel+i-inl, prer-1);
        }else root->right = NULL;
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size()-1;
        in = inorder, po = postorder;
        return re(0, n, 0, n);
    }
};