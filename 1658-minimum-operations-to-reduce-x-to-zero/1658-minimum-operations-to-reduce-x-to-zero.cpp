class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int iter = 0, sums = 0, now = 0;
        for(int i : nums) sums += i;
        if(sums < x)
            return -1;
        if(sums == x) return n;
        sums = sums - x;
        int ans = -1;
        for(int i = 0 ; i < n ; i++)
        {
            now += nums[i];
            while(now > sums)
            {
                now -= nums[iter++];
            }
            if(now == sums) ans = max(ans, (i - iter));
        }
        //cout << ans <<'\n';
        if(ans == -1)
            return -1;
        else return n - ans - 1;
    }
};