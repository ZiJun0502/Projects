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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1)
        {
            TreeNode* node = q.front();
            q.pop();
            if(!node)
            {
                q.push(NULL);
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(node->val);
                if((node->left))
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};