class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(string word : words){
            int i = -1;
            int pos = 0;
            while(pos < word.size()){
                i = s.find(word[pos], i+1);
                if(i == -1) break;
                pos++;
            }
            if(pos == word.size()){
                ans++;
            }
        }
        return ans;
    }
};