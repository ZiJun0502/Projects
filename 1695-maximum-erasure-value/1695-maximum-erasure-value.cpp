class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, n = nums.size();
        //unordered_map<int ,int> m;
        int m[10001];
        memset(m, -1, 4*10001);
        int paSum = 0, maxi = 0;
        for(int i = 0 ; i < n ; i++)
        {
            paSum += nums[i];
            if(m[nums[i]] != -1)
            {
                maxi = max(maxi, paSum - nums[i]);
                int temp = max(l, m[nums[i]] + 1);
                if(temp != l)
                {
                    while(l != temp)
                    {
                        paSum -= nums[l++];
                    }
                }
            }
            m[nums[i]] = i;
        }
        maxi = max(maxi, paSum);
        return maxi;
    }
};