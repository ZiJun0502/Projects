class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = nums.size()-1;
        for(int i = 0 ; i <= count ; i++)
        {
            while(nums[i] == val)
            {
                nums[i] = -1;
                swap(nums[i], nums[count--]);
            }
        }
        return count+1;
    }
};