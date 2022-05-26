class Solution {
public:
    int ans, n ,m;
    vector<vector<int>>* g;
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i, int j)
{
    int count = 0;
    ans += 4;
    (*g)[i][j] = 2;
    if(valid(i + 1, j))
    {
        if((*g)[i + 1][j] == 1)
        {
            dfs(i + 1, j);
            ans--;
        }
        else if((*g)[i + 1][j] == 2)
            ans--;
    }
    if(valid(i - 1, j))
    {
        if((*g)[i - 1][j] == 1)
        {
            dfs(i - 1, j);
            ans--;
        }
        else if((*g)[i - 1][j] == 2)
            ans--;
    }
    //cout << valid(i, j + 1) << '\n' << (*g)[i][j+1] <<'\n';
    if(valid(i, j + 1))
    {
        if((*g)[i][j + 1] == 1)
        {
            dfs(i, j + 1);
            ans--;
        }
        else if((*g)[i][j + 1] == 2)
            ans--;
    }
    if(valid(i, j - 1))
    {
        if((*g)[i][j - 1] == 1)
        {
            dfs(i, j - 1);
            ans--;
        }
        else if((*g)[i][j - 1] == 2)
            ans--;
    }
}
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = &grid;
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j);
                    goto end;
                }
            }
        }
        end:
        return ans;
    }
};