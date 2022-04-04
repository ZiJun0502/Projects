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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* iter = head;
        int count = 1;
        ListNode* temp, * prev;
        prev = NULL,temp = head;
        while(iter != NULL)
        {
            if(count > n)
            {
                prev = temp;
                temp = temp->next;
            }
            iter = iter->next;
            count++;
            
        }
        if(prev == NULL)
        {
            head = temp->next;
            return head;
        }
        prev->next = temp->next;
        
        return head;
    }
};