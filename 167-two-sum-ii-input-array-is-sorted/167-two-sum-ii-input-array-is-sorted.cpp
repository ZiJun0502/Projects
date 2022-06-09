class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(r > l)
        {
            if(nums[r] + nums[l] > target)
            {
                r--;
            }
            else if(nums[r] + nums[l] < target)
            {
                l++;
            }
            else return{l+1,r+1};
        }
        return {};
    }
};