class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 1 ; i < n ; i++) matrix[i][0] += matrix[i-1][0];
        for(int j = 1 ; j < m ; j++) matrix[0][j] += matrix[0][j-1];
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        int ans = 0;
        // two major for loop, looping thorough all possible bottom-right point.
        for(int i = 0 ; i < n ; i++){
            for(int ii = i ; ii < n ; ii++){
                unordered_map<int,int> ma;
                ma[0] = 1;
                int pre;
                for(int j = 0 ; j < m ; j++){
                    pre = matrix[ii][j];
                    if(i > 0)
                        pre -= matrix[i-1][j]; // prefix sum
                    if(ma.find(pre - target) != ma.end()){
                        ans+= ma[pre-target];
                    }
                    ma[pre]++;
                }
            }
        }
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++){
        //         // looping thorough all possible top-left point.
        //         for(int k = 0 ; k <= i ; k++){
        //             for(int l = 0 ; l <= j ; l++){
        //                 int left = l-1 >= 0 ? matrix[i][l-1] : 0;
        //                 int top = k-1 >= 0 ? matrix[k-1][j] : 0;
        //                 int topleft = (l-1>=0 && k-1>=0) ? matrix[k-1][l-1] : 0;
        //                 if(matrix[i][j] - top - left + topleft == target){
        //                     ans++;
        //                 }
        //             }
        //         }
        //     }
        // }
        return ans;
    }
};