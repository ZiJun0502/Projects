/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void find(TreeNode* node, int val)
    {
        if(node)
        {
            if(node->val == val)
            {
                ans = node;
            }
            find(node->right, val);
            find(node->left, val);
        }
        return;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        find(cloned, target->val);
        return ans;
    }
};