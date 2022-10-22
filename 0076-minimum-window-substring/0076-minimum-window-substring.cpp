class Solution {
public:
    unordered_map<char, int> T;
    bool check(unordered_map<char,int>& record){
        for(auto& i : T){
            if(record.find(i.first) == record.end()) return 0;
            if(i.second > record[i.first]){
                return 0;
            }
        }
        return 1;
    }
        
    string minWindow(string s, string t) {
        int ans = 1e5+5;
        string ss;
        unordered_map<char,int> record;
        int n = s.size(), m = t.size();
        for(char c : t){
            T[c]++;
        }
        int l = -1;
        queue<pair<char,int>> last;
        int now = 0;
        for(int i = 0 ; i < n ; i++){
            record[s[i]]++;
            if(T.find(s[i]) != T.end()){
                last.push({s[i], i});
                if(l == -1) l = i;
            }
            
            if(check(record)){
                if(i-l < ans){
                    ans = i - l;
                    ss = string(s.begin()+l, s.begin()+i+1);
                }
                while(!last.empty()){
                    auto j = last.front();
                    record[j.first]--;
                    if(last.size() > 1){
                        last.pop();
                        l = last.front().second;
                    }
                    if(T[j.first] > record[j.first]) break;
                    if(i-l < ans){
                        ans = i - l;
                        ss = string(s.begin()+l, s.begin()+i+1);
                    }
                }
            }
        }
        return ss;
    }
};