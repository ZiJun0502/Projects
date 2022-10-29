class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        int n = plantTime.size();
        for(int i = 0 ; i < n ; i++){
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end(), [](auto& a, auto&b){
            return a.first > b.first;
        });
        int pt = 0, maxi = 0;
        for(int i = 0 ; i < n ; i++){
            pt += v[i].second;
            maxi = max(maxi, pt + v[i].first);
        }
        return maxi;
    }
};