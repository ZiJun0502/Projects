class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> m;
    vector<int> temp;
    int n;
    void hi(vector<int> arr)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        for(auto& i : m)
        {
            if(i.second == 0) continue;
            temp.push_back(i.first);
            i.second--;
            hi(arr);
            temp.pop_back();
            i.second++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            m[nums[i]]++;
        }
        hi(nums);
        return ans;
    }
};