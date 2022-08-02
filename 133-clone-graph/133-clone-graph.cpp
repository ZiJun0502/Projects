/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* visited[101];
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* n = new Node(node->val);
        queue<pair<Node*,Node*>> q;
        q.push({n, node});
        visited[n->val] = n;
        while(!q.empty()){
            Node* now = q.front().first;
            Node* ori = q.front().second;
            q.pop();
            for(Node* child : ori->neighbors){
                if(!visited[child->val]){
                    Node* temp = new Node(child->val);
                    now->neighbors.push_back(temp);
                    q.push({temp, child});
                    visited[temp->val] = temp;
                }
                else{
                    now->neighbors.push_back(visited[child->val]);
                }
            }
        }
        return n;
    }
};