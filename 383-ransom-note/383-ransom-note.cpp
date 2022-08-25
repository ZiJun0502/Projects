class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {};
        for(char c : ransomNote) count[c-'a']++;
        for(char c : magazine) count[c-'a']--;
        for(int i : count) if(i > 0) return false;
        return true;
    }
};