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
    vector<int> arr;
    void traverse(Node* node)
    {
        if(node->children.size() != 0)
        {
            for(auto i : node->children)
            {
                traverse(i);
                arr.push_back(i->val);
            }
        }
        
    }
    vector<int> postorder(Node* root) {
        
        if(root != NULL){
            traverse(root);
            arr.push_back(root->val); 
        }
        return arr;
    }
};