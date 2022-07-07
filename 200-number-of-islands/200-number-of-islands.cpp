class Solution {
public:
    int ans,n,m;
    void DFS(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j] = '0';
        if(i < n && grid[i+1][j] == '1') 
            DFS(i+1, j, grid);
        if(i > 0 && grid[i-1][j] == '1') 
            DFS(i-1, j, grid);
        if(j < m && grid[i][j+1] == '1') 
            DFS(i, j+1, grid);
        if(j > 0 && grid[i][j-1] == '1') 
            DFS(i, j-1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size()-1;
        m = grid[0].size()-1;
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                if(grid[i][j] == '1') {
                    DFS(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};