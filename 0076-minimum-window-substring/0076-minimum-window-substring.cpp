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
        vector<pair<char, int>> last;
        int now = 0;
        for(int i = 0 ; i < n ; i++){
            record[s[i]]++;
            if(T.find(s[i]) != T.end()){
                last.push_back({s[i], i});
                if(l == -1) l = i;
                //cout << s[i] << ' ' << i << '\n';
            }
            
            if(check(record)){
                if(i-l < ans){
                    ans = min(ans, i - l);
                    ss = string(s.begin()+l, s.begin()+i+1);
                }
                while(1){
                    record[last[now].first]--;
                    if(now+1 < last.size())
                    l = last[now+1].second;
                    else l = last[now].second;
                    now++;
                    
                    if(!check(record)) break;
                    else{
                        if(i-l < ans){
                            ans = min(ans, i - l);
                            ss = string(s.begin()+l, s.begin()+i+1);
                        }
                    }
                }
            }
        }
        return ss;
    }
};