class Solution {
public:
    int countVowelPermutation(int n) {
        long long dp[n][5];
        memset(dp, 0, sizeof(dp));
        int mod = 1e9 + 7;
        for(int i = 0 ; i < 5 ; i++) dp[0][i] = 1;
        for(int i = 1 ; i < n ; i++){
            long int a = dp[i-1][0];
            long int e = dp[i-1][1];
            long int ii = dp[i-1][2];
            long int o = dp[i-1][3];
            long int u = dp[i-1][4];
            dp[i][0] = (e + u + ii) % mod;
            dp[i][1] = (a + ii) % mod;
            dp[i][2] = (e + o) % mod;
            dp[i][3] = ii % mod;
            dp[i][4] = (o + ii) % mod;
        }
        long ans = 0;
        
        for(int i : dp[n-1]){
            ans = (ans+i) % mod;
        }
        return ans;
    }
};