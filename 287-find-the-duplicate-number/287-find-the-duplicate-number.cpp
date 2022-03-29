class Solution {
public:
    unordered_map<int,int> m;
    int findDuplicate(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(m[nums[i]] == 0) m[nums[i]]++;
            else return nums[i];
        }
        return 0;
    }
};