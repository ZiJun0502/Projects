class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, n = nums.size();
        unordered_map<int ,int> m;
        int paSum = 0, maxi = 0;
        for(int i = 0 ; i < n ; i++)
        {
            paSum += nums[i];
            if(m.find(nums[i]) != m.end())
            {
                int temp = max(l, m[nums[i]] + 1);
                if(temp != l)
                {
                    while(l != temp)
                    {
                        paSum -= nums[l];
                        l++;
                    }
                }
            }
            maxi = max(maxi, paSum);
            m[nums[i]] = i;
        }
        return maxi;
    }
};