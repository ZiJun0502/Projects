class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        bool good = 0;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < n ; i++){
            auto a = intervals[i];
            if(ans.back()[1] >= a[0]){
                ans.back()[1] = max(ans.back()[1], a[1]);
            }else{
                ans.push_back(a);
            }
        }
        return ans;
    }
};