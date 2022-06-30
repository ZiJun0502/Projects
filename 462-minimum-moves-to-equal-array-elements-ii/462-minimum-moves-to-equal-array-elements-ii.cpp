class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(),nums.end()); // sorting the array
        int l = 0,r = nums.size() - 1;
        while(l<r)
        {
            res += nums[r] - nums[l]; // adding difference
            l++;
            r--;
        }
        return res;
    }
};