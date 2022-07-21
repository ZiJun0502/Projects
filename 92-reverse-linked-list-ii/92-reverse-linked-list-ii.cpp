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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        ListNode* iter, *prev = dummy, *next;
        dummy->next = head;
        for(int i = 1 ; i < left ; i++){
            prev = prev->next;
        }
        iter = prev->next;
        right -= left;
        while(right--){
            next = iter->next;
            iter->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
};