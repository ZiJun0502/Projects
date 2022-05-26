class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, pre = 0;
        unordered_map<int, int> m;
        int n = nums.size();
        m[0] = 1;
        for(int r = 0 ; r < n ; r++)
        {
            pre += nums[r];
            if(m.find(pre - k) != m.end())
                ans+= m[pre - k];
            m[pre]++;
        }
        return ans;
    }
};