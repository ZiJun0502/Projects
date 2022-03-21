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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int>baap;
        
        for(int i = 0; i<lists.size(); i++){
            ListNode*temp = lists[i];
            while(temp != NULL){
                baap.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        sort(baap.begin(), baap.end());
        
        ListNode*si = NULL;
        ListNode*ei = NULL;  
        
        for(int i = 0; i<baap.size(); i++){
            ListNode*te = new ListNode(baap[i]);
            if(si == NULL){
                si = te;
                ei = te;
            }

            else{

                ei->next = te;
                ei = te;
                
            }
        }
        return si;
    }
};