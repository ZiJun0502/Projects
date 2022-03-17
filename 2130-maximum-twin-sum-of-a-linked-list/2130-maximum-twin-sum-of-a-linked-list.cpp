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
    int len = 0;
    int maxi = 0;
    int pairSum(ListNode* head) 
    {
        ListNode* iter = head;
        while(iter != NULL)
        {
            len++;
            iter = iter -> next;
        }
        re(head,0);
        return maxi;
    }
    ListNode* re(ListNode* node, int now)
    {
        ListNode* next = node;
        if(now <= len/2 -1)
        {
            next = re(node->next, now+1);
            if(next == NULL) return NULL;
            int temp = node->val + next->val;
            maxi = max(temp, maxi);
        }
        if(now == len/2) return next;
        else return next->next;
    }
};