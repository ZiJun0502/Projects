class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector pos(256,-1);
        int right = 0 , left = 0;
        int ans = 0;
        //cout << s;
        while(right < s.size())
        {
            if(pos[s[right]] < 0)
            {
                pos[s[right]] = right;
            }
            else 
            {
                left=max(pos[s[right]]+1,left);
                pos[s[right]] = right;
            }
            ans = max(right-left+1,ans);
            right++;
        }
        return ans;
    }
};