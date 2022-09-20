class Solution {
public:
    class trie{
        public:
        trie* next[26] = {};
        int count = 1;
        void insert(string& s){
            trie* iter = this;
            for(char c : s){
                if(iter->next[c - 'a']){
                    iter->next[c - 'a']->count++;
                }
                else{
                    iter->next[c - 'a'] = new trie();
                }
                iter = iter->next[c-'a'];
            }
        }
        int count_res(string& s){
            trie* iter = this;
            int i = 0, count = 0, n = s.size();
            while(i < n && iter->next[s[i] - 'a']){
                count += iter->next[s[i]-'a']->count;
                iter = iter->next[s[i]-'a'];
                i++;
            }
            return count;
        }
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* root = new trie;
        for(string& s : words){
            root->insert(s);
        }
        vector<int> ans(words.size());
        int count = 0;
        for(string& s : words){
            ans[count++] = root->count_res(s);
        }
        return ans;
    }
};