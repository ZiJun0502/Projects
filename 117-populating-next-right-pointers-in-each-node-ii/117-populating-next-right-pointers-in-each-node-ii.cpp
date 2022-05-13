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
        if(!root) return NULL;
        queue<Node*> q;
        Node* iter = new Node(-1), *temp, *dummy = new Node(-1);
        q.push(root);
        int size;
        while(q.empty()!=1)
        {
            size = q.size();
            iter = dummy;
            while(size--)
            {
                temp = q.front();
                q.pop();
                iter->next = temp;
                iter = iter->next;
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return root;
    }
};