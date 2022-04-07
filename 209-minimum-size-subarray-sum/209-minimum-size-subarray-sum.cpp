class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count = 0, r = 0, l = 0;
        int ans = 2327;
        bool hi = false;
        for(r ; r < nums.size() ; r++)
        {
            count += nums[r];
            if(count >= target)
            {
                while(count >= target)
                {
                    count -= nums[l++];
                }
                ans = min(ans, r - l + 2);
                hi = true;
            }
        }
        if(hi) return ans;
        return 0;
    }
};