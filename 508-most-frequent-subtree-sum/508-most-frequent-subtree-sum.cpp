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
    unordered_map<int,int> m;
    int help(TreeNode* root){
        if(!root) return 0;
        int left = help(root->left);
        int right = help(root->right);
        m[left + right + root->val]++;
        return left + right + root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        help(root);
        int maxi = 0;
        vector<int> ans;
        for(auto i : m){
            maxi = max(maxi, i.second);
        }
        for(auto i : m){
            //cout << i.first <<' '<<i.second<<'\n';
            if(i.second == maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};