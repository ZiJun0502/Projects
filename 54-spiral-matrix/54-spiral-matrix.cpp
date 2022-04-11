class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = n * m;
        vector<int> vec;
        int x = -1, y = 0, dx = 1, dy = 0;
        int mini = 0, ymaxi = m - 1, xmaxi = n - 1;
        while(size--)
        {
            y += dy, x += dx;
            vec.push_back(matrix[y][x]);
            if(dx == 1 && x == xmaxi)
            {
                dx = 0;
                dy = 1;
            }
            else if(dy == 1 && y == ymaxi)
            {
                dy = 0;
                dx = -1;
            }
            else if(dx == -1 && x == mini)
            {
                xmaxi--;
                ymaxi--;
                mini++;
                dx = 0;
                dy = -1;
            }
            else if(dy == -1 && y == mini)
            {
                
                dy = 0;
                dx = 1;
            }
        }
        return vec;
    }
};