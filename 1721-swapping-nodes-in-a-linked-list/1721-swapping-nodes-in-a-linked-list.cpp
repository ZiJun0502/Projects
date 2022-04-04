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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* iter = head;
        int len = 0;
        while(iter != NULL)
        {
            iter = iter->next;
            len++;
        }
        iter = head;
        for(int i = 0 ; i < k - 1 ; i++)
            iter = iter->next;
        ListNode* node1 = iter;
        if(k <= len / 2)
            for(int i = 0 ; i < len - 2 * (k - 1) - 1 ; i++)
                iter = iter->next;
        else
        {
            iter = head;
            for(int i = 0 ; i < len - k ; i ++)
            {
                iter = iter->next;
            }
        }
        int temp = iter->val;
        iter->val =node1->val;
        node1->val = temp;
        return head;
    }
};