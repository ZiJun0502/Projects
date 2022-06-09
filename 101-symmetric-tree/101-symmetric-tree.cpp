class Solution {
public:
    bool ans = true;
    bool helper(TreeNode* leftnode,TreeNode* rightnode)
    {
        if(leftnode==NULL && rightnode==NULL)
            return true;
        if(leftnode->left!=NULL && rightnode->right!=NULL)
		{
			if(leftnode->left->val != rightnode->right->val)
			{
                       return false;
			}
        
			else
			{
				ans = ans && helper(leftnode->left,rightnode->right);
				if(!ans)
					return ans;
			}
        }
        else if((leftnode->left != NULL && rightnode->right==NULL) ||(leftnode->left==NULL && rightnode->right!=NULL))
            return false;
			
        if(leftnode->right && rightnode->left)
		{
			if(leftnode->right->val != rightnode->left->val)
				return false;
			 else
			{
				ans = ans && helper(leftnode->right,rightnode->left);
				if(!ans)
					return ans;
			}
        }
        else if((leftnode->right != NULL && rightnode->left==NULL) ||(leftnode->right==NULL && rightnode->left!=NULL))
            return false;
            
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right) 
            return true;
        return helper(root,root);
    }
};