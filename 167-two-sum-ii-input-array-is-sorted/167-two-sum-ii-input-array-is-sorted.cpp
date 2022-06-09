class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size(); r--;
        int temp;
        while(r > l)
        {
            temp = nums[r] + nums[l];
            if(temp > target)
            {
                r--;
            }
            else if(temp < target)
            {
                l++;
            }
            else return{l+1,r+1};
        }
        return {};
    }
};