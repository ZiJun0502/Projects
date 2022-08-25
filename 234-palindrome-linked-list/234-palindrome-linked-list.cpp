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
        ListNode* now, *prev = NULL, *next = head, *go;
        now = head, go = head->next;
        while(go && go->next){
            go = go->next->next;
            now = next;
            next = now->next;
            now->next = prev;
            prev = now;
        }
        if(go){
            now = next;
            next = now->next;
            now->next = prev;
            prev = now;
            go = next;
        }else go = next->next;
        
        while(go){
            //cout << go->val << ' ' << now->val <<'\n';
            if(go->val != now->val) return 0;
            go = go->next, now = now->next;
        }
        return 1;
    }
};