class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int len = 0;
        int l = 0,r = nums.size() - 1;
        for(l ; nums[l] == arr[l] && l < r ; l++)
        {}
        for(r ; nums[r] == arr[r] && r > l ; r--)
        {}
        return r - l == 0 ? 0 : r - l + 1;
    }
};