class MyStack {
public:
    int arr[100];
    int size = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        arr[size++] = x;
    }
    
    int pop() {
        size--;   
        return arr[size];
    }
    
    int top() {
        return arr[size-1];
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */