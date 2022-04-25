class Solution {
public:
    int climbStairs(int n) {
        int ans,a0,a1;
        ans = a0 = a1 = 1;
        for(int i = 0 ; i < n-1 ; i++)
        {
            ans = a0 + a1;
            a0 = a1;
            a1 = ans;
        }
        return ans;
    }
};