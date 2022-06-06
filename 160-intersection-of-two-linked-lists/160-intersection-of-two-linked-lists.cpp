/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        int len1 = 0, len2 = 0;
        while(iter1)
        {
            iter1 = iter1->next;
            len1++;
        }
        while(iter2)
        {
            iter2 = iter2->next;
            len2++;
        }
        int move1 = len1 - len2;
        int move2 = -1*move1;
        iter1 = headA, iter2 = headB;
        while(move1 > 0)
        {
            iter1 = iter1->next;
            move1--;
        }
        while(move2 > 0)
        {
            iter2 = iter2->next;
            move2--;
        }
        while(iter1 != iter2)
        {
            iter1 = iter1->next;
            iter2 = iter2->next;
        }
        return iter1;
    }
};