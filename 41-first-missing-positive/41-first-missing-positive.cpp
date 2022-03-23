class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int togo;
        for(int i = 0 ; i < len ; i++)
        {
            if(nums[i] < 0) continue;
            togo = nums[i] - 1;
            while(togo < len && togo >= 0 && nums[togo]!= nums[i])
            {
                swap(nums[togo], nums[i]);
                togo = nums[i] - 1;
            }
        }
        for(int i = 0 ; i < len ; i++)
        {

            if(nums[i] != i+1) return i + 1;
        }
        return len + 1;
    }
};