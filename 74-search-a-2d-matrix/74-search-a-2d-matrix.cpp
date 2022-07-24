class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = matrix.size(), down = 0, mid;
        int n = up;
        while(up >= down){
            mid = (up + down) / 2;
            if(mid >= n){
                up--;
                break;
            }
            if(matrix[mid][0] > target) up = mid-1;
            else if(matrix[mid][0] < target) down = mid+1;
            else return true;
        }
        if(up < 0) return false;
        auto i = lower_bound(matrix[up].begin(), matrix[up].end(), target);
        if(i != matrix[up].end() && (*i) == target) return true;
        return false;
    }
};