class FreqStack {
public:
    unordered_map<int,int> freq;// map from element id to count
    unordered_map<int,stack<int>> top;

    int max = 0;
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        top[freq[val]].push(val);
        if(freq[val] > max)
        {
            max = freq[val];
        }
    }
    
    int pop() {
        int topp = top[max].top();
        top[max].pop();
        cout << topp;        
        freq[topp]--;
        if(top[max].empty()) max--;
        return topp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */