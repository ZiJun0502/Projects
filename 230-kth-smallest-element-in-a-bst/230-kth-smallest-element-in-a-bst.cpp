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
    int count = 0;
    int num = 0;
    void traverse(TreeNode* root, int k) {
        if(root->left != NULL)
        {
            traverse(root->left,k);
        }
        count++;
        if(count == k)
        {
            num = root->val;
            return;
        }
        if(root->right != NULL)
        {
            traverse(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return num;
    }
};