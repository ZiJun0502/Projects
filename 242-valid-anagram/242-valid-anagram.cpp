class Solution {
public:
    bool isAnagram(string s, string t) {
        short int m[26] = {};
        for(char c : s){
            m[c-'a']++;
        }
        for(char c : t){
            m[c-'a']--;
        }
        for(int i = 0 ; i < 26 ;i++){
            if(m[i] != 0) return false;
        }
        return true;
    }
};