class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int len0 = nums.size();
        vector<int> vec(len0,-1);
        int len = 2 * k + 1;
        if(k == 0) return nums;
        long sum = 0;
        for(int i = 0 ; i < len && i < len0 ; i++)
        {
            sum += nums[i];
        }
        int l = 0, r = len;
        for(int i = len ; i < len0; i++)
        {
            vec[i - k - 1] = sum / len;
            sum -= nums[i - len];
            sum += nums[i];
        }
        if(len0 - k - 1 > 0)
            vec[len0 - k - 1] = sum / len;
        return vec;
    }
};