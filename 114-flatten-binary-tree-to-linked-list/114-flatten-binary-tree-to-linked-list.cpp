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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root)
        {
            TreeNode* right = root->right;
            if(prev)
            {
                prev->right = root;
                prev->left = NULL;
            }
            prev = root;
            flatten(root->left);
            flatten(right);
        }
    }
};