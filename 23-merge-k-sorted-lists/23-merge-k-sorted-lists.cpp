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
    struct comp{
        bool operator()(const ListNode* a, const ListNode* b) {
          return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto i : lists)
            if (i != NULL)
                pq.push(i);
        if(pq.empty()) return NULL;
        ListNode* head = new ListNode(pq.top()->val);
        ListNode* iter = head; 
        ListNode* temp= pq.top()->next;
        pq.pop();
        if (temp != NULL)
        pq.push(temp);
        
        while(pq.empty() != 1)
        {
            temp = pq.top();
            iter->next = temp;
            iter = iter->next;
            pq.pop();
            if(temp->next != NULL)
            pq.push(temp->next);
        }
        return head;
    }
};