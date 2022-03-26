class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int ans = 0;
        int endpt = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(i + nums[i] > farthest)
            {
                farthest = i + nums[i];
                if(farthest >= n-1) return ans+1;
            }
            if(i == endpt)
            {
                endpt = farthest;
                ans++;
            }
        }
        return ans;
    }
};