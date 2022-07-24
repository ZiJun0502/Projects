class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> m;
        string s;
        sort(words.begin(), words.end());
        m.insert("");
        int ans = 0;
        for(string word : words){
            int n = word.size();
            if(m.find(word.substr(0, n-1)) != m.end()){
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