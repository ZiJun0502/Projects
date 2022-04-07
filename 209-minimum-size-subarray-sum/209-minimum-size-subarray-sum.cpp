class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = 0, r = 0, l = 0;
        int ans = 10000;
        bool hi = false;
        for(r ; r < nums.size() ; r++)
        {
            count += nums[r];
            while(count >= target)
            {
                ans = min(ans, r - l + 1);
                count -= nums[l++];
                hi = true;
            }
        }
        if(hi) return ans;
        return 0;
    }
};