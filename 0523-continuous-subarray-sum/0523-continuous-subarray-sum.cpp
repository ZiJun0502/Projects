class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> m;
        int pref = 0, last = 0;
        for(int i = 0 ; i < n ; i++){
            //if(pref == 0 && nums[i] == 0) continue;
            pref = (pref + nums[i]) % k;
            if(m.find(pref) != m.end()){
                return true;
            }
            m.insert(last);
            last = pref;
        }
        return false;
    }
};