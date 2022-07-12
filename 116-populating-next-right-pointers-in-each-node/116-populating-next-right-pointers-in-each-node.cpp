/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        list<Node*> q;
        if(!root) return NULL;
        root->next = NULL;
        q.push_back(root);
        q.push_back(NULL);
        Node* temp = NULL;
        int count;
        while(q.size() > 1){
            temp = q.front();
            q.pop_front();
            if(temp == NULL){
                q.push_back(NULL);
                continue;
            }
            temp->next = q.front();
            if(temp->left){
                q.push_back(temp->left);
            }
            if(temp->right){
                q.push_back(temp->right);
            }
        }
        return root;
    }
};