class Solution {
public:
    
    void DFS(Node* root, vector<Node*>& depths, int depth) {
        root->next = depths[depth];
        depths[depth] = root;
        if(root->right != NULL) DFS(root->right, depths, depth+1);
        if(root->left != NULL) DFS(root->left, depths, depth+1);
    }
    
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        vector<Node*> depths(13, NULL);
        DFS(root, depths, 0);
        return root;
    }
};