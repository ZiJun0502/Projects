class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = -1;
        //prefix sub sorted array
        int i = 0;
        for(i ; i < n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                left = i;
                break;
            }  
        }
        if(i == n-1) return 0;
        
        for(i = n-1; i > 0; i--)
        {
            if(nums[i] < nums[i-1])
            {
                right = i;
                break;
            }
            
        }
        if(i == 0) return 0;
        int mini = *min_element(nums.begin() + left + 1, nums.end());
        int min = upper_bound(nums.begin(), nums.begin() + left, mini) - nums.begin();
        
        int maxi = *max_element(nums.begin(), nums.begin() + right);
        int max = lower_bound(nums.begin() + right, nums.end(), maxi) - nums.begin();
        return max - min;
    }
};