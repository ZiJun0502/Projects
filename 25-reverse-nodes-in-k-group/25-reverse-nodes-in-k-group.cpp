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
    int leng(ListNode* node)
    {
        int ans = 0;
        while(node!=NULL)
        {
            node = node->next;
            ans++;
        }
        return ans;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = leng(head);
        if(k == 1) {return  head;}
        // ListNode dummy = ListNode(-1);
        // ListNode* s = &dummy;
        // s->next = head;
        ListNode *s = reverseGroup(&head, k);
        for(int i = 0 ; i < len/k-1 ; i++)
        {
            s = reverseGroup(&(s->next),k); // return last end point
        }
        return head;
    }
    ListNode* reverseGroup(ListNode** s, int k)
    {
        ListNode* now = (*s);
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* groupHead = (*s);
        while(--k)
        {
            next = now->next;
            now->next = prev;
            prev = now;
            now = next;
        }
        groupHead->next = now->next;
        now->next = prev;
        (*s) = now;
        return groupHead;
    }
};