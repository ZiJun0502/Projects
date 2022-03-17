class Solution {
public:
    string longestPalindrome(string s) {
        int j = 0,maxd = 0;
        string ans; ans.push_back(s[0]);
        if(s.size() == 1) return s;
        for(int i = 1 ; i < s.size() ; i++)
        {
            if(s[i] == s[i-1])
            {
                for(j = 1 ; (i-1)-j >= 0 && s[i+j] == s[(i-1)-j] ; j++){}
                if(j*2 > maxd)
                {
                    maxd = j<<1;
                    ans = s.substr(i-j,maxd);
                }
            }
            if(i>= 2 && s[i] == s[i-2])
            {
                for(j = 1 ; i-2-j >= 0 && s[i+j] == s[i-2-j] ; j++){}
                if(j*2+1 > maxd)
                {
                    maxd = j*2 + 1;
                    ans = s.substr(i-j-1,maxd);
                }
            }
        }
        return ans;
    }
};