class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum;
        sum = 0;
        for(int i = 1 ; i < n ; i++){
            sum += max(prices[i] - prices[i - 1], 0);
        }
        return sum;
    }
};