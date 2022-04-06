class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iter = 0;
        map<int,int> m;
        for(int i = 0 ; i < nums.size() ; i++)
            m[nums[i]] = 1;
        int len = 0;
        for(auto i : m)
        {
            nums[len++] = i.first;
        }
        return len;
    }
};