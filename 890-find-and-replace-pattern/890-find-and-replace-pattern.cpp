class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<int, int> freq;
        short int id[26] = {};
        int len = pattern.size();
        char mask[len];
        int now = 1, count = 0;
        for(char c : pattern){
            if(!id[c-'a']){
                mask[count++] = now;
                id[c-'a'] = now++;
            }
            else{
                mask[count++] = id[c-'a'];
            }
        }
        vector<string> ans;
        for(string s : words){
            short int temp[26] = {};
            char smask[len];
            count = 0, now = 1;
            for(char c : s){
                if(!temp[c-'a']){
                    smask[count++] = now;
                    temp[c-'a'] = now++;
                } else smask[count++] = temp[c-'a'];
            }
            bool good = 1;
            for(int i = 0 ; i < len ; i ++){
                if(mask[i] != smask[i]){
                    good = 0;
                    break;
                }
            }
            if(good) ans.push_back(s);
        }
        return ans;
    }
};