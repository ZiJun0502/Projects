class Solution {
public:
    vector<int> nums, mul;
    int dp[1001][1001];
    int n, m;
    int re(int now, int l, int r){
        if(now == m) return 0;
        if(dp[l][now] != -2) return dp[l][now];
        int left =  mul[now] * nums[l] + re(now+1, l+1, r);
        int right =  mul[now] * nums[r] + re(now+1, l, r-1);
        //cout << left << ' ' << right<<'\n';
        dp[l][now] = max(left, right);
        return dp[l][now];
    }
    int maximumScore(vector<int>& _nums, vector<int>& _mul) {
        nums = _nums, mul = _mul;
        n = nums.size(), m = mul.size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < m; j++) dp[i][j] = -2;
        }
        return re(0, 0, n-1);
    }
};