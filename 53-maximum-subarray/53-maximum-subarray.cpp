class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r = 0;
        int ans = -2147483648;
        int temp = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            temp+=nums[r];
            ans = max(ans, temp);
            if(temp < 0)
            {
                ++r;
                temp = 0;
            }
            else r++;
        }
        return ans;
    }
};