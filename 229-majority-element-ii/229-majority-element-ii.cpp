class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            m[nums[i]]++;
            
        }
        for(auto i : m){
            if(i.second > n/3) ans.push_back(i.first);
        }
        return ans;
    }
};