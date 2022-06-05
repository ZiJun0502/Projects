class Solution {
public:
    bool col[9], row[9], left[18], right[18];
    int ans;
    int n;
    bool valid(int i, int j)
    {
        return !(col[j] || row[i] || right[i + j] || left[j - i + n]);
        
    }
    void solve(int i = 0)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(valid(i, j))
            {
                if(i == n - 1)
                {
                    ans++;
                    return;
                }
                col[j] = 1,
                row[i] = 1,
                left[j - i + n] = 1,
                right[i + j] = 1;
                solve(i + 1);
                col[j] = row[i] = left[j - i + n] = right[i + j] = 0;
            }
        }
    }
    int totalNQueens(int nn) {
        n = nn;
        solve();
        return ans;
    }
};