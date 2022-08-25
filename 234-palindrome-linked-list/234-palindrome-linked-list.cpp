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
        ListNode* now, *prev = NULL, *next, *go;
        now = head, go = head;
        while(go && go->next){
            go = go->next->next;
            next = now->next;
            now->next = prev;
            prev = now, now = next;
        }
        if(go){
            go = now->next;
        }
        else go = now;
        while(go){
            //cout << go->val << ' ' << now->val <<'\n';
            if(go->val != prev->val) return 0;
            else go = go->next, prev = prev->next;
        }
        return 1;
    }
};