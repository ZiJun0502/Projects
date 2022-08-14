class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        if(n == 1) return 0;
        int right = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] > right){
                ans += (nums[i] - 1) / right;
                right = nums[i] / (((nums[i] - 1) / right)+1);
            }else{
                right = nums[i];
            }
        }
        return ans;
    }
};