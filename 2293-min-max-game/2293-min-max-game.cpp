class Solution {
public:
    int re(vector<int>& nums, int l = 0, int r = 0, int flag = 0){
        if(r - l > 1){
            int left = re(nums, l, (l+r)/2, 0);
            int right = re(nums, (l+r)/2+1, r, 1);
            if(flag) return max(left, right);
            else return min(left, right);
        }
        else{
            if(flag) return max(nums[l], nums[r]);
            else return min(nums[l], nums[r]);
        }
        return 0;
    }
    int minMaxGame(vector<int>& nums) {
        return re(nums, 0, nums.size()-1);
    }
};