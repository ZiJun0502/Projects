class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for(int i = 0 ; i <= amount ; i++) dp[i] = -1;
        dp[0] = 0;
        for(int i = 1 ; i <= amount ; i++)
        {
            for(int j : coins)
            {
                if(j > i || dp[i - j] == -1) continue;
                if(dp[i] != -1)
                    dp[i] = min(dp[i - j] + 1, dp[i]);
                else dp[i] = dp[i - j] + 1;
            }
        }
        int count = 0;
        //for(auto i : dp) cout << count++ << ':'<< i << '\n';
        return dp[amount];
    }
};