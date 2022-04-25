class Solution {
public:
    int climbStairs(int n) {
        int ans = 1;
        int a0 = 1;
        int a1 = 1;
        n-=1;
        while(n--)
        {
            ans = a0 + a1;
            a0 = a1;
            a1 = ans;
        }
        return ans;
    }
};