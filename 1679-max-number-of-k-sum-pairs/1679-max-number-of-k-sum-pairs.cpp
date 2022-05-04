class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(m[nums[i]] > 0)
            {
                ans++;
                m[nums[i]]--;
            }
            else
            {
                m[k - nums[i]]++;
                
            }
        }
        return ans;
    }
};