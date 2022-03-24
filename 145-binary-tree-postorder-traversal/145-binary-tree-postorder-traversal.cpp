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
    vector<int> arr;
    void traverse(TreeNode* node)
    {
        if(node == NULL)return;
        if(node->left != NULL) traverse(node->left);
        if(node->right != NULL) traverse(node->right);
        arr.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return arr;
    }
};