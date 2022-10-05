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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        short int rot[100001];
        memset(rot, -1, sizeof(rot));
        TreeNode* m[100001] = {};
        int p, c;
        bool left;
        for(vector<int>& i : d){
            p = i[0], c = i[1];
            left = i[2];
            rot[c] = 0;
            if(rot[p] == -1) rot[p] = 1;
            if(!m[p]){
                m[p] = new TreeNode(p);   
            }
            if(!m[c]){
                m[c] = new TreeNode(c);
            }
            if(left){
                m[p]->left = m[c];
            }else m[p]->right = m[c];
        }
        for(int i = 0 ; i < 100001 ; i++){
            if(rot[i] == 1) return m[i];
        }
        return NULL;
    }
};