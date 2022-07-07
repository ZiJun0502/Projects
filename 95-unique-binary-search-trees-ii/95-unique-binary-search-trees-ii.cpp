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
    vector<TreeNode*> ans;
    int n;
    vector<TreeNode*> re(int l, int r)
    {
        // choose starting point
        if(l == r){
            return {new TreeNode(l)};
        }
        vector<TreeNode*> left, right, ans;
        for(int i = l ; i <= r ; i++)
        {
            //all possible left subtree and right subtree
            if(i > l)
                left = re(l, i-1);
            else left = {NULL};
            if(i < r)
                right = re(i+1, r);
            else right = {NULL};
            for(TreeNode* ll : left)
            {
                for(TreeNode* rr : right)
                {
                    ans.push_back(new TreeNode(i, ll, rr));
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return re(1, n);
    }
};