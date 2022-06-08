class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(j)
        {
            if(s[i] != s[j]) return 2;
            j--;
            i++;
        }
        return 1;
    }
};