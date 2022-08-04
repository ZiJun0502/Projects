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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool direction = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        stack<TreeNode*> s;
        while(q.size() > 1){
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL){
                direction = !direction;
                if(!direction)
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                q.push(NULL);
            }
            else{
                temp.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        if(direction)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        
        return ans;
    }
};