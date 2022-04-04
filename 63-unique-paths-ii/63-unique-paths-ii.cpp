class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    if(i == 0 || j == 0) obstacleGrid[i][j] = 1;
                    else obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                }
                else {
                    obstacleGrid[i][j] = 0;
                    if(i == 0) for(int k = j+1 ; k < m ; k++) obstacleGrid[0][k] = 1;
                    if(j == 0) for(int k = i+1 ; k < n ; k++) obstacleGrid[k][0] = 1;
                }
            }
        }
        // for(int i = 0 ; i < n ; i ++)
        // {
        //     for(int j = 0 ; j < m ; j++)
        //     {
        //         cout << obstacleGrid[i][j] <<' ';
        //         }
        //     cout << '\n';
        // }
        return obstacleGrid[n - 1][m - 1];
    }
};