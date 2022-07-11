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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        ans.push_back(root->val);
        TreeNode* temp;
        int last;
        while(q.size() > 1){
            temp = q.front();
            q.pop();
            if(temp == NULL){
                q.push(NULL);
                ans.push_back(last);
                continue;
            }
            if(temp->left){
                q.push(temp->left);
                last = temp->left->val;
            }
                
            if(temp->right){
                q.push(temp->right);
                last = temp->right->val;
            }                
        }
        return ans;
    }
};