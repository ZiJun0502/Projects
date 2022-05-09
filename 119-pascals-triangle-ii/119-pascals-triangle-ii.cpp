class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return{1};
        vector<int> ans(rowIndex + 1);
        long long coml = 1;
        ans[0] = ans[rowIndex] = 1;
        for(int i = 1 ; i < rowIndex ; i++)
        {
            coml = coml * (rowIndex - i + 1) / i;
            ans[i] = coml;
        }
        return ans;
    }
};