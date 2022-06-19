class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& ss, string s) {
        sort(ss.begin(), ss.end());
        vector<vector<string>> ans;
        int m = s.size();
        int l = 0, r = ss.size()-1;
        // we only need to check those strings between l and r.
        // the other strings are eliminated in the first iteration.
        for(int i = 0 ; i < m ; i++)
        {
            char c = s[i];
            vector<string> temp;
            while(l <= r && (i >= ss[l].size() || ss[l][i] < c)) 
                l++;
            while(l <= r && (i >= ss[r].size() || ss[r][i] > c)) 
                r--;
            for(int j = l ; j <= r && j < l + 3 ; j++)
                temp.push_back(ss[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};