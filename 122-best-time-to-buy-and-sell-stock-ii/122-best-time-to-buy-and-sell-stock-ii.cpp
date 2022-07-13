class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size()-1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += max(prices[i+1] - prices[i], 0);
        }
        return sum;
    }
};