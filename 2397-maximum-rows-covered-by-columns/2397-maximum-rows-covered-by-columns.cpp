class Solution {
public:
    int next_popcount(int n) {
    int c = (n & -n), r = n + c;
    return (((r ^ n) >> 2) / c) | r;
}
int maximumRows(vector<vector<int>>& mat, int cols) {
    int m = mat.size(), n = mat[0].size(), res = 0;
    for (int mask = (1 << cols) - 1; mask < (1 << n); mask = next_popcount(mask)) {
        int rows = 0;
        for (int i = 0, j = 0; i < m; ++i) {
            for (j = 0; j < n; ++j)
                if (mat[i][j] && (mask & (1 << j)) == 0)
                    break;
            rows += j == n;
        }
        res = max(res, rows);
    }
    return res;
}
};