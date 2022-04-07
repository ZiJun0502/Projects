class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int len0 = nums.size();
        int len = 2 * k + 1;
        if(k == 0) return nums;
        vector<int> vec(len0,-1);
        if(len > len0)
            return vec;
        long sum = 0;
        for(int i = 0 ; i < len ; i++)
        {
            sum += nums[i];
        }
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