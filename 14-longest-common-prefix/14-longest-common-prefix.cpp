class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        char temp;
        for(int i = 0 ; ; i++)
        {
            if(i >= strs[0].size()) 
                return ans;
            temp = strs[0][i];
            for(int j = 0; j < strs.size() ; j++)
            {
                if(strs[j][i] != temp) 
                {return ans;}
            }
            ans.push_back(temp);
        }
        return ans;
    }
};