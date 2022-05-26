class Solution {
public:
    int ans, n ,m;
    vector<vector<int>>* g;
    void dfs(int i, int j)
    {
        int count = 0;
        ans += 4;
        (*g)[i][j] = 2;
        if(i+1 < n)
        {
            if((*g)[i + 1][j] == 1)
            {
                dfs(i + 1, j);
                ans--;
            }
            else if((*g)[i + 1][j] == 2)
                ans--;
        }
        if(i-1 >= 0)
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
        if(j+1 < m)
        {
            if((*g)[i][j + 1] == 1)
            {
                dfs(i, j + 1);
                ans--;
            }
            else if((*g)[i][j + 1] == 2)
                ans--;
        }
        if(j-1 >= 0)
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