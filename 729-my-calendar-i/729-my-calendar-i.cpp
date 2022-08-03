class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto i = m.lower_bound(start);
        if(i != m.end() && end > i->first) return false;
        if(i != m.begin() && (--i)->second > start) return false;
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */