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
        bool good = 1;
        if(root->left){
            good = re(root->left);
        }
        if(good == 0) return 0;
        if(root->val <= last) return false;
        //cout << root->val << '\n';
        last = root->val;
        if(root->right)
            good = re(root->right);
        if(good == 0) return 0;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return re(root);
    }
};