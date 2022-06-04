class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool col[9], row[9], left[18], right[18];
    int n;
    bool valid(int i, int j)
    {
        return !(col[j] || row[i] || right[i + j] || left[j - i + n]);
        
    }
    void solve(int i)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(valid(i, j))
            {
                temp[i][j] = 'Q';
                if(i == n - 1)
                {
                    ans.push_back(temp);
                    temp[i][j] = '.';
                    return;
                }
                col[j] = 1;
                row[i] = 1;
                left[j - i + n] = 1;
                right[i + j] = 1;
                solve(i + 1);
                temp[i][j] = '.';
                col[j] = row[i] = left[j - i + n] = right[i + j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int nn) {
        n = nn;
        temp = vector<string>(n, string(n, '.'));
        solve(0);
        return ans;
    }
};