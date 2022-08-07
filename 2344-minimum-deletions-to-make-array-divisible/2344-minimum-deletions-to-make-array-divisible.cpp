class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& d) {
        int n = d.size();
        map<int,int> m;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }
        sort(d.begin(), d.end());
        int ans = 0;
        for(auto i : m){
            int key = i.first;
            bool good = 1;
            for(int j = 0 ; j < n ; j++){
                //if(j > 0 && d[j] == d[j-1]) continue;
                if(d[j] % key != 0){
                    ans += i.second;
                    //cout << i.first <<'\n';
                    good = 0;
                    break;
                }
            }
            if(good) break;
        }
        if(ans == nums.size()) return -1;
        return ans;
    }
};