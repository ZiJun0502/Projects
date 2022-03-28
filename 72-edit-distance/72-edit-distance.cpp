class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int a = word1.size();
        int b = word2.size();
        int dp[a + 1][b + 1];// dp[i][j] denote the number of operations to convert word1[0:i] to word2[0:j]
        for(int i = 0 ; i <= a ; i++)
        {
            for(int j = 0 ; j <= b ; j++)
            {
                if(i==0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp[a][b];
    }
};