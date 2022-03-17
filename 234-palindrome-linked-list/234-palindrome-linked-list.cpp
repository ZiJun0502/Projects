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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* iter = head;
        while(iter != NULL)
        {
            len++;
            iter = iter->next;
        }
        ListNode* mid = head;
        // get mid
        for(int i = 0 ; i < len / 2  ; i++)
        {
            mid = mid -> next;
        }
        if(len %2 != 0) mid = mid ->next;
        // reverse half of the linked list
        ListNode* next = NULL;
        ListNode* prev = NULL;
        iter = head;
        for(int i = 0 ; i < len/2 ; i++)
        {
            next = iter->next;
            iter->next = prev;
            prev = iter;
            iter = next;
        }
        for(int i = 0 ; i < len / 2 ; i++)
        {
            if(prev->val != mid->val) return false;
            prev = prev->next;
            mid = mid->next;
        }
        return true;
    }
};