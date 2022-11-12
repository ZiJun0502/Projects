class Solution {
public:
    long long dp[101][101][101];
    int n, m;
    long long dfs(vector<int>& ro,vector<vector<int>>& fac, int i, int j, int k){
        if(i == n) return 0;
        if(j == m) return 1e18;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int lim = fac[j][1], pos = fac[j][0];
        long long fix, skip;
        fix = k < lim ? abs(ro[i] - pos) + dfs(ro, fac, i+1, j, k+1) : 1e18;
        skip = dfs(ro, fac, i, j+1, 0);
        return dp[i][j][k] = min(fix, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& fac) {
        sort(robot.begin(), robot.end());
        sort(fac.begin(), fac.end());
        n = robot.size(), m = fac.size();
        memset(dp, -1, sizeof(dp));
        
        return dfs(robot, fac, 0, 0, 0);
    }
};