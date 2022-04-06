class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        char temp;
        for(int i = 0 ; ; i++)
        {
            if(i >= strs[0].size()) goto end;
            temp = strs[0][i];
            for(string s : strs)
            {
                if(i >= s.size()) goto end;
                if(s[i] != temp)
                    goto end;
            }
            ans.push_back(temp);
        }
        end:
        return ans;
    }
};