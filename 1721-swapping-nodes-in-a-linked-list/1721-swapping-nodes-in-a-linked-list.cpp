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
        int temp;
        if(k <= len / 2)
        {
            temp = len - 2 * (k - 1) - 1;
            for(int i = 0 ; i < temp ; i++)
                iter = iter->next;
        }
        else
        {
            temp = len - k;
            iter = head;
            for(int i = 0 ; i < temp ; i ++)
                iter = iter->next;
        }
        temp = node1->val;
        node1->val = iter->val;
        iter->val = temp;
        return head;
    }
};