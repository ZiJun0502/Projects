class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int l = n-1, r = n-1;
        for(l; l > 0 ; l--){
            if(nums[l] > nums[l-1]){
                l--;
                for(r ; r > l ; r--){
                    if(nums[r] > nums[l]){
                        break;
                    }
                }
                swap(nums[l], nums[r]);
                reverse(nums.begin()+l+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        
        
    }// 1 2 5 3 4 6
     // 1 2 5 3 6 4
     // 1 2 5 4 3 6
     // 1 2 5 4 6 3
     // 1 2 5 6 3 4
     // 1 2 7 6 8 4 3
     // 1 2 6 3 4 5
};