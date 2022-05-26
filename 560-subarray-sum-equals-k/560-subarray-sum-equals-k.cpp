class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, pre = 0;
        unordered_map<int, int> m;
        
        for(int r = 0 ; r < nums.size() ; r++)
        {
            pre += nums[r];
            if(pre == k) ans++;
            ans+= m[pre - k];
            m[pre]++;
        }
        return ans;
    }
};