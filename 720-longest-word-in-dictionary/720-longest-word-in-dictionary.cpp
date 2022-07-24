class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> m;
        string s;
        m.insert("");
        int ans = 0;
        int n;
        for(string word : words){
            n = word.size();
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