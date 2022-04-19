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
    TreeNode* node1, *prev, *node2;
    void traverse(TreeNode* root) {
        if(root != NULL)
        {
            traverse(root->left);
            if(prev && root->val < prev->val)
            {
                if(node1 == NULL)
                {
                    node1 = prev;
                    node2 = root;
                }
                else 
                {
                    node2 = root;
                    return;
                }
            }
            prev = root;
            traverse(root->right);
        }
    }
    void recoverTree(TreeNode* root)
    {
        traverse(root);
        swap(node1->val, node2->val);
    }
};