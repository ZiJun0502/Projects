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
    vector<int> ans;
    void traverse(TreeNode* node)
    {
        ans.push_back(node->val);
        if(node->left != NULL)
            preorderTraversal(node->left);
        if(node->right != NULL)
            preorderTraversal(node->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)return ans;
        traverse(root);
        return ans;
    }
};