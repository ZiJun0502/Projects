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
        int pos[n];
        memset(pos, 0, sizeof(pos));
        int size = 0;
        int now = 0;
        for(int i = 0 ; i < n ; i++){
            record[s[i]]++;
            if(T.find(s[i]) != T.end()){
                pos[size++] = i;
                if(l == -1) l = i;
            }
            if(check(record)){
                if(i-l < ans){
                    ans = i - l;
                    ss = string(s.begin()+l, s.begin()+i+1);
                }
                while(1){
                    int last = pos[now++];
                    record[s[last]]--;
                    if(now < size){
                        l = pos[now];
                    }
                    if(T[s[last]] > record[s[last]]) break;
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