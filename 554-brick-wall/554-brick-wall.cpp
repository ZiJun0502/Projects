class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = 0, maxi = 0;
        for(int i : wall[0]) n += i;
        unordered_map<int,int> count;
        for(auto i : wall){
            int len = 0;
            for(int j : i){
                len += j;
                if(len != n){
                count[len-1]++;
                maxi = max(maxi, count[len-1]);
                }
             
            }
        }
        return wall.size() - maxi;
    }
};