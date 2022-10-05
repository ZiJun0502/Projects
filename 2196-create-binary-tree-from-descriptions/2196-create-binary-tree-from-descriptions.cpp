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
        unordered_map<int,bool> rot;
        unordered_map<int,TreeNode*> m;
        for(auto i : d){
            int p = i[0], c = i[1];
            bool left = i[2];
            rot[c] = 0;
            if(rot.find(p) == rot.end()) rot[p] = 1;
            if(m.find(p) == m.end()){
                m[p] = new TreeNode(p);   
                rot[p] = 1;
            }
            if(m.find(c) == m.end()){
                m[c] = new TreeNode(c);
            }
            if(left){
                m[p]->left = m[c];
            }else m[p]->right = m[c];
        }
        for(auto i : rot){
            if(i.second){
                return m[i.first];
            }
        }
        return NULL;
    }
};