class Solution {
public:
    int minDistance(string word2, string word1) 
    {
        int a = word1.size();
        int b = word2.size();
        int dp[b + 1];// dp[i][j] denote the number of operations to convert word1[0:i] to word2[0:j]
        for(int i = 0 ; i <= b ; i++) dp[i] = i;
        int i0 = 1; // first element in i-th row
        int temp = dp[0]; // record the dp[i-1][j-1] element
        int tempp = 0;
        for(int i = 1 ; i <= a ; i++)
        {
            //for(auto i : dp) cout << i <<' '; cout <<'\n';  

            for(int j = 0 ; j <= b ; j++)
            {
                if(j != 0)
                {
                    tempp = dp[j];
                    if(word1[i-1] == word2[j-1]) dp[j] = temp;
                    else dp[j] = 1 + min(temp, min(dp[j], dp[j - 1]));
                    temp = tempp;
                }
                else
                {
                    temp = dp[j];
                    dp[j] = i;
                }
            }
            //for(auto i : dp) cout << i <<' '; cout <<'\n';  

        }
        
        return dp[b];
    }
};