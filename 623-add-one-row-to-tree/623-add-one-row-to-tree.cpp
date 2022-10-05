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
    int depth, val;
    void re(TreeNode* root, int dep){
        if(dep+1 == depth){
            TreeNode* node0, *node1;
            node0 = new TreeNode(val);
            node1 = new TreeNode(val);
            node0->left = root->left, node1->right = root->right;
            root->left = node0, root->right = node1;
            return;
        }
        if(root->left)
        re(root->left, dep+1);
        if(root->right)
        re(root->right, dep+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val_, int depth_) {
        depth = depth_, val = val_;
        if(depth == 1){
            TreeNode* temp, *node;
            node = new TreeNode(val);
            node->left = root;
            return node;
        }
        re(root, 1);
        return root;
    }
};