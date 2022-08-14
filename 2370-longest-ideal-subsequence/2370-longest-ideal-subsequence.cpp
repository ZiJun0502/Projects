class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26] = {};
        for(char c : s){
            dp[c-'a'] = dp[c-'a']+1;
            for(int i = 0 ; i < 26 ; i++){
                if(abs(c-'a' - i) <= k && c-'a' != i){
                    dp[c-'a'] = max(dp[c-'a'], dp[i]+1);
                }
            }
        }
        //for(int i : dp) cout << i <<' ';
        return *max_element(dp, dp+26);
    }
};