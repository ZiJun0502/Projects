class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(m[nums[i]] > 0)
            {
                ans++;
                m[nums[i]]-=1;
            }
            else if(k > nums[i] && nums[i] > 0)
            {
                m[k - nums[i]]++;
            }
            else
            {
                nums[i] = -1;
            }
            
        }
        return ans;
    }
};