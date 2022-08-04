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
    //divide and conquer
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l = root, * r = root;
        int leftH = 0, rightH = 0;
        while(l){
            l = l->left;
            leftH++;
        }
        while(r){
            r = r->right;
            rightH++;
        }
        if(rightH == leftH) return (1<<rightH)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};