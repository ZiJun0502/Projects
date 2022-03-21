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
public://using min heap
    vector<ListNode*> arr;
    int len;
    void swapNode(ListNode** a, ListNode**b)
    {
        ListNode* temp = *a;
        *a = *b;
        *b = temp;
    }
    void heapify(int i)
    {
        if(i*2+1 <= len)
        {
            if(i*2+2 <= len)
            {
                if(arr[i]->val > arr[i*2+1]->val || arr[i]->val >arr[i*2+2]->val)
                {
                    if(arr[i*2+1]->val < arr[i*2+2]->val)
                    {
                        swapNode(&arr[i], &arr[i*2+1]);
                        heapify(i*2+1);
                    }
                    else
                    {
                        swapNode(&arr[i], &arr[i*2+2]);
                        heapify(i*2+2);
                    }
                }
            }
            if(arr[i]->val > arr[i*2+1]->val)
            {
                swapNode(&arr[i], &arr[i*2+1]);
                return;
            }
            heapify(i*2+1);
        }
        return;
    }
    void insert(ListNode* node)
    {
        arr.push_back(node);
        // for(auto i : arr)
        // {
        //     cout << i->val <<' ';
        // }
        // cout <<'\n';
        heapify_b(arr.size()-1);
        
    }
    void heapify_b(int i)//bottom up heapify for insertion
    {
        if(i == 0)
        {
            return;
        }
        else
        {
            if(arr[i]->val < arr[(i-1)/2]->val)
            {
                swapNode(&arr[i], &arr[(i-1)/2]);
                heapify_b((i-1)/2);
            }
        }
    }
    ListNode* makeNode(int val)
    {
        ListNode* node = new ListNode(val);
        return node;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto i : lists)
        {
            if(i != NULL)
            insert(i);
        }
        len = arr.size()-1;
        if(len < 0 || arr[0] == NULL) return NULL;
        if(len == 0) return arr[0];
        ListNode* head = makeNode(arr[0]->val);
        ListNode* iter = head;
        ListNode* node;
        if(arr[0]->next == NULL)
            {
                if(len > 0)
                swapNode(&arr[0],&arr[len--]);
            }
        else
            arr[0] = arr[0]->next;
        heapify(0);
        for(;;)
        {
            node = makeNode(arr[0]->val);
            //cout<<node->val<<' ';
            iter->next = node;
            iter = iter->next;
            if(arr[0]->next == NULL)
            {
                if(len > 0)
                swapNode(&arr[0],&arr[len--]);
                else break;
            }
            else
                arr[0] = arr[0]->next;
            heapify(0);
        }
        return head;
    }
};