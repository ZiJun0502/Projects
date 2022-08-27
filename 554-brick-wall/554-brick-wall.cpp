class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        auto temp = wall[0];
        int n = 0;
        for(int j : temp) n += j;
        unordered_map<int,int> count;
        for(auto i : wall){
            int len = 0;
            for(int j : i){
                len += j;
                if(len != n)
                count[len-1]++;
            }
        }
        //for(int i : count)cout << i <<' ';
        int maxi = 0;
        for(auto i : count){
            maxi = max(i.second, maxi);
        }
        return wall.size() - maxi;
    }
};