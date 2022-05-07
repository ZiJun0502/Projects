class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int stack[n];
        int size = 0;
        int second = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(nums[i] < second) return true;
            else
            {
                while(size > 0 && nums[i] > stack[size - 1])
                {
                    second = stack[--size];
                }
            }
            stack[size++] = nums[i];
        }
        return false;
    }
};