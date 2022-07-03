class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        int dp[n+1];
        memset(dp, 0, 4 * (n+1));
        dp[1] = 1;
        int mod = 1e9 + 7;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i + delay ; j < n + 1 && j - i < forget; ++j)
            {
                dp[j] = (dp[j] + dp[i]) % mod;
            }
            if(i + forget > n)
            {
                ans = (ans + dp[i]) % mod;
            }
        }
        //for(int i : dp) cout << i <<' ';
        //cout << '\n';
        //for(int i : know) cout << i <<' ';
        //cout << '\n';
        return ans;
    }
};