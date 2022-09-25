class MyCircularQueue {
public:
    struct Node{
        int val;
        Node* next, *before;
        Node(int v){
            val = v;
        }
    };
    Node* head, *tail;
    int size, maxi;
    MyCircularQueue(int k) {
        head = new Node(-1);
        tail = head;
        size = 0;
        maxi = k;
    }
    
    bool enQueue(int value) {
        if(size == maxi) return false;
        tail->next = new Node(value);
        tail->next->before = tail;
        tail = tail->next;
        size++;
        return true;
    }
    
    bool deQueue() {
        //cout << "hi";
        if(size == 0) return false;
        if(size == 1){
            tail = head;
            head->next = NULL;
        }
        else{
            head->next = head->next->next;
            head->next->before = head;
        }
        size--;
        return true;
    }
    
    int Front() {
        return head->next ? head->next->val : -1;
    }
    
    int Rear() {
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxi;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */