class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> m;
        int ans = 0;
        string s;
        sort(words.begin(), words.end());
        for(string word : words){
            int n = word.size();
            if(n == 1){
                m.insert(word);
                if(n > ans){
                    ans = n;
                    s = word;
                }else if(n == ans && word < s) s = word;
            }
            else if(m.find(word.substr(0, n-1)) != m.end()){
                if(n > ans){
                    ans = n;
                    s = word;
                }
                else if(n == ans){
                    if(word < s) s = word;
                }
                m.insert(word);
            }
            
        }
        return s;
    }
};