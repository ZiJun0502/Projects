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
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* iter = head;
        while(iter != NULL)
        {
            iter = iter->next;
            len++;
        }
        if(len == 1) return NULL;
        iter = head;
        for(int i = 0 ; i < len/2-1 ; i++)
            iter = iter->next;
        iter->next = iter->next->next;
        return head;
    }
};