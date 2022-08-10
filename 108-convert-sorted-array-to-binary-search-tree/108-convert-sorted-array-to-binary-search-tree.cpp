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
    vector<int> arr;
    TreeNode* re(int l, int r){
        if(r < l) return NULL;
        int mid = (r+l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = re(l, mid-1);
        root->right = re(mid+1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        arr = nums;
        return re(0, nums.size()-1);
    }
};