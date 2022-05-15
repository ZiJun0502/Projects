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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dum = new ListNode(-1);
        ListNode* iter = dum;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        for(;cur1 && cur2;)
        {
            if(cur1->val >= cur2->val)
            {
                iter = iter->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                iter = iter->next = cur1;
                cur1 = cur1->next;
            }
        }
        while(cur1)
        {
            iter = iter->next = cur1;
            cur1 = cur1->next;
        }
        while(cur2)
        {
            iter = iter->next = cur2;
            cur2 = cur2->next;
        }
        return dum->next;
    }
};