class Solution {
public:
    int uniquePaths(int m, int n) {
       int mod = 2e9;
        long long ans = 1;
        int temp = min(m, n) -1;
        int j = m+n-2;
        for(int i = 1 ; i <= temp ; i++){
            ans = ans * j-- / i % mod;
        }
        return ans;
    }
};