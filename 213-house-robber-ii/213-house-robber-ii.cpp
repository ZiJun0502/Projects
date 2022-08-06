class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        for(int i = 1 ; i < n ; i++){
            dp[i][0] += max(dp[i-1][0], dp[i-1][1]);
            if(i >= 2)
            dp[i][1] += max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1])) + nums[i];
            else{
                dp[i][1] += dp[i-1][0] + nums[i];
            }
        }
        int temp = max(dp[n-1][0], dp[n-1][1]);
        memset(dp, 0, sizeof(dp));
        dp[0][1] = nums[0];
        for(int i = 1 ; i < n-1 ; i++){
            dp[i][0] += max(dp[i-1][0], dp[i-1][1]);
            if(i >= 2)
            dp[i][1] += max(dp[i-1][0], max(dp[i-2][0], dp[i-2][1])) + nums[i];
            else{
                dp[i][1] += dp[i-1][0] + nums[i];
            }
        }
        return max(temp, max(dp[n-2][0], dp[n-2][1]));
    }
};