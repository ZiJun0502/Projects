class Solution {
public:
    set<int> s;
    int findDuplicate(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(s.count(nums[i]) == 0) s.insert(nums[i]);
            else return nums[i];
        }
        return 0;
    }
};