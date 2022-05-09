class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return{1};
        vector<int> ans;
        int com = 1;
        long long coml = 1;
        ans.push_back(1);
        for(int i = 1 ; i < rowIndex ; i++)
        {
            coml = coml * (rowIndex - i + 1) / i;
            com = coml;
            ans.push_back(com);
        }
        ans.push_back(1);
        return ans;
    }
};