class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> col, row;
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(matrix[i][j] == 0)
                {
                    col.push_back(j);
                    row.push_back(i);
                }
            }
        }
        for(int j : col)
        {
            //cout << j <<'\n';
            for(int i = 0 ; i < n ; i++)
                matrix[i][j] = 0;
        }
        for(int i : row)
        {
            //cout << i <<'\n';
            for(int j = 0 ; j < m ;j++)
                matrix[i][j] = 0;
        }
    }
};