class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(m[nums[i]] == 0) m[nums[i]]++;
            else return nums[i];
        }
        return 0;
    }
};