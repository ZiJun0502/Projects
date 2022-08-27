class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int count[26];
        memset(count, -1, sizeof(count));
        int ans = n;
        for(int i = n-1 ; i >= 0 ; i--){
            if(count[s[i] - 'a'] == -1){
                count[s[i] - 'a'] = i;
            }
            else count[s[i] - 'a'] = -2;
        }
        for(int& i : count){
            if(i >= 0) ans = min(i, ans);
        }        
        return ans == n ? -1 : ans;
    }
};