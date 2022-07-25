class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = -1, l = -1, n = nums.size();
        for(int i = 0 ; i < n ;i++){
            if(nums[i] == target){
                if(f == -1){
                    f = i;
                }
                l = i;
            }
        }
        return {f, l};
    }
};