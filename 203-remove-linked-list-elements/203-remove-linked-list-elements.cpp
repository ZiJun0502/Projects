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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev;
        ListNode* next, *iter = head;
        iter = head;
        while(iter && iter->val == val)
        {
            head = head->next;
            delete iter;
            iter =  head;
        }
        while(iter)
        {
            next = iter->next;
            if(iter->val == val)
            {
                prev->next = next;
                delete iter;
            }
            else
                prev = iter;
            iter = next;
        }
        return head;
    }
};