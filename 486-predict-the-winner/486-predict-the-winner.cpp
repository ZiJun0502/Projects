class Solution {
public:
    vector<vector<int>> dp;    
    vector<int>::iterator iter;
    int re(int start, int end)
    {
        if(start > end) return 0;
        if(dp[start][end] != 0) return dp[start][end]; // get rid of overlapping subproblems.
        // taking minimum here is to simulate that the player 2 is playing the game optimally.
        int choice1 = iter[start] + min(re(start + 2, end), re(start + 1, end - 1)); 
        int choice2 = iter[end] + min(re(start + 1, end - 1), re(start, end - 2)); 
        return dp[start][end] = max(choice1, choice2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        iter = nums.begin();
        int sum =0;
        int n = nums.size();
        iter = nums.begin();
        dp = vector<vector<int>>(n, vector<int>(n));
        for(int i = 0; i < n; i++) 
            sum += nums[i];
        int p1 = re(0, nums.size() - 1); 
        return p1 >= sum - p1;
    }
};