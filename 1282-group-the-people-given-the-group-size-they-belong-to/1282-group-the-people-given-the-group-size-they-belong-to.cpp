class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        vector<int> count[n+1];
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            count[group[i]].push_back(i);
            if(count[group[i]].size() == group[i]){
                ans.push_back(count[group[i]]);
                count[group[i]].clear();
            }
        }
        return ans;
    }
};