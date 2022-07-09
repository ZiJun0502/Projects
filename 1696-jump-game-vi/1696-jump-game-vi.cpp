class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dp;
        dp.emplace_front(nums[0], 0);
        for(int i = 1 ; i < n ; i++){
            while(dp.front().second + k < i){
                dp.pop_front();
            }
            int score = dp.front().first + nums[i];
            while(!dp.empty() && score >= dp.back().first ){
                dp.pop_back();
            }
            dp.emplace_back(score, i);
        }
        return dp.back().first;
    }
};