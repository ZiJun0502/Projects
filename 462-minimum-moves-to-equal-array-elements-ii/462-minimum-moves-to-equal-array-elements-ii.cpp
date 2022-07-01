class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end()); // sorting the array
        int l = 0,r = nums.size() - 1;
        while(l<r)
        {
            ans += nums[r--] - nums[l++]; // adding difference
        }
        return ans;
    }// 1 4 5 7 8 // 7 3
};