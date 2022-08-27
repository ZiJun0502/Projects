class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int count[202] = {};
        for (auto n : nums)
            ++count[n + 100];
        sort(begin(nums), end(nums), [&](int a, int b) {
           return count[a + 100] == count[b + 100] ? a > b : count[a + 100] < count[b + 100];
        });
        return nums;
    }
};