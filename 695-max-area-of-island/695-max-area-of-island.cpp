class Solution {
public:
    bool visited[50][50];
    int n, m, area, maxArea;
    void DFS(int i, int j, vector<vector<int>>& grid)
    {
        visited[i][j] = 1;
        area+=1;
        if(i < n && grid[i+1][j] == 1 && !visited[i+1][j]) DFS(i+1, j , grid); 
        if(i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) DFS(i-1, j , grid); 
        if(j < m && grid[i][j+1] == 1 && !visited[i][j+1]) DFS(i, j+1 , grid); 
        if(j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) DFS(i, j-1 , grid); 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size()-1;
        m = grid[0].size()-1;
        for(int i = 0 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= m ; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = 1;
                    area = 0;
                    DFS(i , j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};