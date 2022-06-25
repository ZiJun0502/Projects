class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int temp = 0;              
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                if(++temp > 1) return false;
                if(!(i == 1 || nums[i-2] <= nums[i]))
                    nums[i] = nums[i-1];
            }
        }
        return true;
    } 
};