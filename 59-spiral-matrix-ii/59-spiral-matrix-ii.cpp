class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n));
        int size = n * n;
        int x = -1, y = 0, dx = 1, dy = 0;
        int mini = 0, maxi = n - 1;
        
        for(int k = 1 ; k <= size ; k++)
        {
            y += dy, x += dx;
            ans[y][x] = k;
            if(dx == 1 && x == maxi)
            {
                dx = 0;
                dy = 1;
            }
            else if(dy == 1 && y == maxi)
            {
                dy = 0;
                dx = -1;
            }
            else if(dx == -1 && x == mini)
            {
                maxi--,mini++;
                dx = 0;
                dy = -1;
            }
            else if(dy == -1 && y == mini)
            {
                
                dy = 0;
                dx = 1;
            }
        }
        return ans;
    }
};