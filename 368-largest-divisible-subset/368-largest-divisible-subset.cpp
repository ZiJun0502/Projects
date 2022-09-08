class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() ,nums.end());
        vector<int> ans;
        vector<vector<int>> dp(n);
        dp[0].push_back(nums[0]);
        for(int i = 1 ; i < n ; i ++){
            int maxi = 0, ind = -1;
            for(int j = i-1 ; j >= 0 ; j--){
                if(dp[j].size() > maxi && nums[i] % nums[j] == 0){
                    ind = j, maxi = dp[j].size();
                }
            }
            vector<int> temp;
            if(ind != -1){
                temp = dp[ind];;
            }
            temp.push_back(nums[i]);
            dp[i] = temp;
        }
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i].size() > maxi){
                maxi = dp[i].size();
                ans = dp[i];
            }
        }
        return ans;
    }
};