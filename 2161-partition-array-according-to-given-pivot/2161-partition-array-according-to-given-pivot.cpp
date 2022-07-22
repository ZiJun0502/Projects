class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l;
        vector<int> r;
        vector<int> m;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < pivot){
                l.push_back(nums[i]);
            }else if(nums[i] > pivot)r.push_back(nums[i]);
            else m.push_back(nums[i]);
        }
        l.insert(l.end(), m.begin(), m.end());
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
};