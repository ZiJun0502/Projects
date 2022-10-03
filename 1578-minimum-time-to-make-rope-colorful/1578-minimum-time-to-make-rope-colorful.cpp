class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size(), maxi;
        for(int i = 0 ; i < n-1 ; i++){
            if(colors[i] == colors[i+1]){
                maxi = neededTime[i];
                while(i < n-1 && colors[i] == colors[i+1]){
                    maxi = max(neededTime[i+1], maxi);
                    ans += neededTime[i];
                    i++;
                }
                ans += neededTime[i] - maxi;
            }
            
        }
        return ans;
    }
};