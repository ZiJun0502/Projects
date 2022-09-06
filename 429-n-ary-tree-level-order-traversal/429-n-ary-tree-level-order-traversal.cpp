/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(q.size() > 1){
            Node* node = q.front();
            q.pop();
            if(node == NULL){
                q.push(NULL);
                ans.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(node->val);
                for(Node* i : node->children){
                    q.push(i);
                }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};