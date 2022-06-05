class Solution {
public:
    vector<int> grayCode(int n) {
        n = pow(2, n);
        vector<int> ans(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            ans[i] = i ^ (i/2);
        }
        return ans;
    }
};