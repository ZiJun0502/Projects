#define pii pair<int, int>
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> dp(nums.size(),0);
        dp[n-1]=nums[n-1];
        
        deque<int> dq;
        dq.push_back(n-1);
      
        for(int i=n-2;i>=0;i--){
          
            
            while(!dq.empty() && dq.front() > i + k){
              dq.pop_front();
            }
            
            int score = dp[dq.front()];
            dp[i] = nums[i] + score;
           
            while(!dq.empty() && dp[dq.back()]<= dp[i]){
              dq.pop_back();
            } 
            
            dq.push_back(i); 
            
        }
        
        return dp[0];}
};