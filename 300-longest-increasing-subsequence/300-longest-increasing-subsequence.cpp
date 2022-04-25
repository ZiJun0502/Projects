class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] denote the maximum length of LIS ending at point i
        int dp[n];
        for(int i = 0 ; i < n ; i++) {dp[i] = 1;}
        int ans = 1;
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                    ans = max(dp[i],ans);
                }
            }
        }
        return ans;
    }
};