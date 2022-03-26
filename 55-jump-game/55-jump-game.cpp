class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size()-1;
        if(n == 0) return true;
        int far = 0;
        for(int i = 0 ; i < n ; i++)
        {
            far = max(far, i + nums[i]);
            if(i == far)
            {
                return false;
            }
        }
        return true;
    }
};