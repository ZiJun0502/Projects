class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        int maxi;
        while(right >= left){
            int mid = (left + right) / 2;
            
            int smaller = 0;
            maxi = INT_MIN;
            for(int i = 0 ; i < n ; i++){
                auto temp = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
                smaller += temp - matrix[i].begin();
                
                if(temp != matrix[i].begin())
                maxi = max(*(temp-1), maxi);
                else maxi = min(*(temp), maxi);
                //cout << maxi << '\n';
            }
            //cout << smaller  <<' '<< left << ' ' << right <<' '<< '\n';
            if(smaller > k) right = mid-1;
            else if(smaller < k) left = mid + 1;
            else {
                return maxi;
            }
        }
        return right+1;
    }
};