class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1 ; i < n ; i++)
        {
            triangle[i][0] = triangle[i][0] + triangle[i-1][0];
            for(int j = 1 ; j < i ; j++)
            {

                triangle[i][j] = min(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
            }
            triangle[i][i] = triangle[i][i] + triangle[i-1][i-1];
        }
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j : dp[i]) 
        //         cout << j <<' ';
        //     cout << '\n';
        // }
        int mini = INT_MAX;
        n--;
        for(int i = 0 ; i <= n ; i++)
        {
            mini = min(triangle[n][i], mini);
        }
        return mini;
    }
};