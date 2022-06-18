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
    int n;
    int status(TreeNode* node)
    {
        if(!node) return 0;
        int l = status(node->left);
        int r = status(node->right);
        if(l == 0 && r == 0) return 1;// child already covered, but root need help
        if(l == 1 || r == 1)
        {
            n++;
            return 2;
        }
        if(l == 2 || r == 2)
        {
            return 0;
        }
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        if(root)
        {
            if(status(root) == 1)
                n++;
            return n;
        }
        return 0;
    }
};