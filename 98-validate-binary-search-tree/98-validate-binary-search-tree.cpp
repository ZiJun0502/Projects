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
    long last = -2147483649;
    bool re(TreeNode* root){
        if(root->left)
            if(!re(root->left)) return 0;
        
        if(root->val <= last) return false;
        //cout << root->val << '\n';
        last = root->val;
        if(root->right)
            if(!re(root->right)) return 0;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return re(root);
    }
};