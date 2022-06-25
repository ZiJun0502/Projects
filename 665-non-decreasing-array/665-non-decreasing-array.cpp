class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool check = false;             
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                if(!(i == 1 || nums[i-2] <= nums[i]))
                {
                    nums[i] = nums[i-1];
                }
                if(check)
                    return false;
                else
                    check = true;
            }
        }
        return true;
    } 
};