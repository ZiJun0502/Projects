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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root->val > val)
        {
            if(root->left == NULL) return NULL;
            return searchBST(root->left, val);
        }
        else if(root->val < val)
        {
            if(root->right == NULL) return NULL;
            return searchBST(root->right, val);
        }
        else
            return root;
        return NULL;
    }
};