class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        //for(int i = 0 ; i < n ; i++) dp[i][0] = 1;
        //for(int i = 0 ; i < m ; i++) dp[0][i] = 1;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        // for(int i = 0 ; i <= n ; i++){
        //     for(int j = 0 ; j <= m ; j++){
        //         cout << dp[i][j] <<' ';
        //     }cout << '\n';
        // }
        return ans;
        
    }
};