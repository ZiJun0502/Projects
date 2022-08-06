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
    int last;
    bool first = 1;
    int ans = INT_MAX;
    void re(TreeNode* root){
        if(root->left) re(root->left);
        if(first){
            first = 0;
            last = root->val;
            
        }else{
            ans = min(ans, root->val - last);
            last = root->val;
        }
       
        if(root->right) re(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        re(root);
        return ans;
    }
};