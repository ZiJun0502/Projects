class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro = 1, temp = 1;
        int n = nums.size(), count = 0;
        for(int i = 0 ; i < n ; i++){
            pro *= nums[i];
            if(nums[i] == 0) count++;
            else temp *= nums[i];
        }
        vector<int> ans(n);
        if(count > 1) return ans;
        for(int i = 0 ; i < n ; i++) if(nums[i] != 0) ans[i] = pro / nums[i];
        else ans[i] = temp;
        return ans;
    }
};