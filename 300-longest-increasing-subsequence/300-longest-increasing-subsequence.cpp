class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] denote the maximum length of LIS ending at point i
        vector<int> dp;
        int l = 1;
        dp.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] > dp.back())
            {
                dp.push_back(nums[i]);
                l++;
            }
            else
            {
                int temp = lower_bound(dp.begin(), dp.end(), nums[i])- dp.begin();
                dp[temp] = nums[i];
            }
        }
        return l;
    }
};