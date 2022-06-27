class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            int temp = nums[i];
            if(m.find(temp) != m.end())
            {
                return {m[temp], i};
            }
            m[target - temp] = i;
        }
        return {};
    }
};