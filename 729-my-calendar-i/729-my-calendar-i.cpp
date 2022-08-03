class MyCalendar {
public:
    vector<int> starts;
    vector<int> finish;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(starts.empty()){
            starts.push_back(start);
            finish.push_back(end);
            return true;
        }
        auto i = upper_bound(starts.begin(), starts.end(), start);
        //cout <<start<<' '<< i - starts.begin()<<'\n'; 
        
        if(i == starts.end()){
            int last = finish[(i-starts.begin())-1];
            //cout << last <<'\n';
            if(last > start) return false;
            finish.insert(finish.begin()+(i-starts.begin()),end);
            starts.insert(i, start);
        }
        else {
            if(end > *i) return false;
            if(i != starts.begin()){
                int last = finish[i-starts.begin()-1];
                if(last > start) return false;
            }
            finish.insert(finish.begin()+(i-starts.begin()),end);
            starts.insert(i, start);
            
        }
        // for(int i : starts) cout << i <<' ';
        // cout <<'\n';
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */