class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i = 0 ; i < n ;i++){
            auto j = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(j != matrix[i].end() && (*j) == target) return true;
        }
        return false;
    }
};