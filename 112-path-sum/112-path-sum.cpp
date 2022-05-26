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
private:
    bool hasPathSumHelper(TreeNode* currNode, int targetSum, int currSum)
    {
        bool hasSum = false;
        // case: currNode is not in tree
        if (currNode)
        {
            currSum += currNode->val;
            // case: leaf node encountered
            if (!currNode->left && !currNode->right && currSum == targetSum)
            {
                hasSum = true;
            }
            // case: internal node encountered
            else
            {
                hasSum = (hasPathSumHelper(currNode->left, targetSum, currSum) || hasPathSumHelper(currNode->right, targetSum, currSum)); 
            }
        }
        return hasSum;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumHelper(root, targetSum, 0);
    }
};