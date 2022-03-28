class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int dp[b+1];
        for(int i = 0 ; i <= b ; i++) dp[i] = 0;
        int tempp , temp ;
        for(int i = 1 ; i <= a ; i++)
        {
            for(int j = 1 ; j <= b ; j++)
            {
                tempp = dp[j];
                if(nums1[i-1] == nums2[j-1]) 
                {
                    dp[j] = j==1? 1 : temp + 1;
                }
                else dp[j] = max(dp[j-1], dp[j]);
                temp = tempp;
            }  
        }
        return dp[b];
    }
};