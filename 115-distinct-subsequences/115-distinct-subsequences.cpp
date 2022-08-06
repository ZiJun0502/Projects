class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int dp[n+1][m+1];
        int maxi = 2147483647;
        for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
        for(int i = 1 ; i <= m ; i++) dp[0][i] = 0;
        for(int j = 1 ; j <= m ; j++){
            for(int i = 1 ; i <= n ; i++){
                if(s[i-1] == t[j-1]){
                    if(maxi - dp[i-1][j] > dp[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};