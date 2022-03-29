class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    void solver(int target, vector<int>& arr, int count)
    {
        if(target == 0) 
            ans.push_back(vec);
        
        for(int i = count; i < arr.size() ; i++)
        {
            if(target - arr[i] >= 0)
            {
                vec.push_back(arr[i]);
                solver(target - arr[i], arr, i);
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solver(target, candidates, 0);
        return ans;
        
    }
};