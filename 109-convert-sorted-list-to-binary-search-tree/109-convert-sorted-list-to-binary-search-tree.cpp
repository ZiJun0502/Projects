/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* re(ListNode* head){
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* mid = head;
        ListNode* before = head;
        ListNode* forward = head->next;
        while(forward){
            forward = forward->next;
            if(forward){
                forward = forward->next;
                before = mid;
                mid = mid->next;
            }
        }
        TreeNode* root = new TreeNode(mid->val);
        root->right = re(mid->next);
        before->next = NULL;
        if(head != mid)
        root->left = re(head);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return re(head);
    }
};