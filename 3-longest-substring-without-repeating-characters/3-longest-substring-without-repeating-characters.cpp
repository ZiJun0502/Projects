class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos, -1, 1024);
        //for(int i : pos) cout << i <<' ';
        int n = s.size();
        char c;
        int left = 0, ans = 0;
        for(int i  = 0 ; i < n ; i++)
        {
            c = s[i];
            if(pos[c] != -1)
            {
                left = max(left, pos[c] + 1) ;
                //cout << c << ":" <<pos[c] <<'\n';
            }
            ans = max(ans, i - left + 1);
            pos[c] = i;
        }
        return ans;
    }
};