class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[m];
        dp[0] = grid[0][0];
        int now = grid[0][0];
        for(int j = 1 ; j < m ; j++) dp[j] = grid[0][j] + dp[j-1];
        for(int i = 1 ; i < n ; i ++)
        {
            now += grid[i][0];
            for(int j = 1 ; j < m ;j++)
            {
                if(j == 1)
                {
                    dp[j] = min(dp[j], now) + grid[i][j];
                }
                else
                {
                    dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                }
            }
            
        }
        return dp[m-1];
    }
};