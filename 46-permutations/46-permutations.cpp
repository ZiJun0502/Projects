class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums, int start, int end){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<=end;i++){
            swap(nums[i],nums[start]);
            helper(nums,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0,nums.size()-1);
        return ans;
    }
};