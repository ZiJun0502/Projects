class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= m * n;
        
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> vec(n);
        int startingRow = (m - k / m) - 1 % m;
        int startingCol = n == 1 ? 0 : n - k % n;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                ans[(i + (j + k)/ n) % m][(j + k % n) % n] = grid[i][j];
            }
        }
        return ans;
    }
};