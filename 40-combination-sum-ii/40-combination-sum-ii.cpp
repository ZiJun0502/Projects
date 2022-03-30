class Solution {
public:
    vector<int> vec;
    vector<vector<int>> ans;
    int len; 
    void solver(int val, vector<int>& arr ,int count = 0)
    {
        if(val == 0){
            ans.push_back(vec);
            return;
        }
        for(int i = count ; i < len ; i++)
        {
            if(i > count && arr[i] == arr[i - 1]) continue;
            if(arr[i] > val) continue;
            vec.push_back(arr[i]);
            solver(val-arr[i], arr, i + 1);
            vec.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        len = candidates.size();
        sort(candidates.begin(), candidates.end());
        solver(target, candidates);
        return ans;
    }
};