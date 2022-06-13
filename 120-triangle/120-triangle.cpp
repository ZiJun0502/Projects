class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int **dp;
        dp = new int*[n];
        for(int i = 0 ; i < n ; i++)
            dp[i] = new int[i+1];
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j <= i ; j++)
            {
                //cout << i <<' '<<j<<'\n';
                dp[i][j] = 10000;
                //cout << dp[i][j] <<' ';
            }
            //cout << '\n';
        }
        // vector<vector<int>> dp;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     dp.push_back(vector<int>(i+1, 10000));
        // }
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j : dp[i]) 
        //         cout << j <<' ';
        //     cout << '\n';
        // }
        //cout << dp[1][0] <<' '<<triangle[1][0] <<' '<<dp[0][0]<<'\n';
        dp[0][0] = triangle[0][0];
        for(int i = 1 ; i < n ; i++)
        {
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for(int j = 1 ; j < i ; j++)
            {

                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
            dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        }
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j : dp[i]) 
        //         cout << j <<' ';
        //     cout << '\n';
        // }
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            mini = min(dp[n-1][i], mini);
        }
        return mini;
    }
};