class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[target+1];
        int maxi = INT_MAX;
        //memset(dp, 0, 4*(target+1));
        for(int &i : dp) i = 0;
        dp[0] = 1;
        for(int j = 1 ; j <= target ; j++){
            for(int i = 0 ; i < n ; i++){
                if(nums[i] <= j){
                    if(dp[j] > maxi - dp[j-nums[i]]) break;
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        return dp[target];
    }
};