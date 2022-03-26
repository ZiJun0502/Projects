class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,10000);
        dp[0] = 0;
        for(int i = 0 ; i < n-1 ; i ++)
        {
            for(int j = 1 ; j <= nums[i] && j+i < n ; j++)
            {
                dp[j+i] = min(dp[i]+1, dp[j+i]);
            }
        }
        // for(int i = 0 ; i < n ; i++)
        //     cout << dp[i] <<' ';
        return dp[n-1];
    }
};