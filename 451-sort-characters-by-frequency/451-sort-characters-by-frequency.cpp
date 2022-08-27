class Solution {
public:
    int find(char c){
        if(c >= 'a' && c <= 'z') return c-'a';
        else if(c >= 'A' && c <= 'Z') return c-'A'+26;
        else return c-'0'+52;
    }
    int findd(int i){
        if(i >= 0 && i < 26) return i+'a';
        else if(i >= 26 && i < 52) return i-26+'A';
        else return i+'0'-52;
    }
    string frequencySort(string s) {
        int count[62] = {};
        for(char c : s){
            count[find(c)]++;
        }
        priority_queue<pair<int, char>> q;
        string ans;
        for(int i = 0 ; i < 62 ; i++){
            if(count[i])
                q.push({count[i], findd(i)});
        }
        while(!q.empty()){
            auto i = q.top();
            q.pop();
            ans += string(i.first, i.second);
        }
        return ans;
    }
};