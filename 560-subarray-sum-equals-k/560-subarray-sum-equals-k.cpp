class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            nums[i] += nums[i-1];
        }
        unordered_map<int,int> m;
        int ans = 0;
        m[0] = 1;
        for(int i : nums){
            if(m.find(i - k) != m.end()){
                ans += m[i - k];
            }
            m[i]++;
        }
        return ans;
    }
};