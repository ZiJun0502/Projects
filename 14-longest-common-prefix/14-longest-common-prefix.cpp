class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        char temp;
        for(int i = 0 ; ; i++)
        {
            if(i >= strs[0].size()) return ans;
            temp = strs[0][i];
            for(string s : strs)
            {
                if(i >= s.size() || s[i] != temp) return ans;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};