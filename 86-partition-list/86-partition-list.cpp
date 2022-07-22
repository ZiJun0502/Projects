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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        ListNode* iter = head, *prev = NULL, *next = NULL;
        ListNode* diter = dummy;
        while(iter){
            next = iter->next;
            if(iter->val >= x){
                diter->next = iter;
                diter = diter->next;
                if(prev != NULL){
                    prev->next = iter->next;
                }
                else{
                    head = next;
                }
                iter->next = NULL;
            }
            else
                prev = iter;
            iter = next;
        }
        if(prev != NULL) prev->next = dummy->next;
        else return dummy->next;
        return head;
    }
};