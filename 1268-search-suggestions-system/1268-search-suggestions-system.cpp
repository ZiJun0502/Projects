class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& ss, string s) {
        sort(ss.begin(), ss.end());
        int n = ss.size();
        int iter = 0;
        int m = s.size();
        vector<vector<string>> ans;
        for(int i = 0 ; i < m ; i++)
        {
            vector<string> temp;
            string sub = s.substr(0, i + 1);
            for(int j = 0 ; j < n ; j++)
            {
                string t = ss[j].substr(0, i+1);
                //cout << t <<' ' <<sub<<'\n';
                if(t == sub)
                {
                    temp.push_back(ss[j]);
                }
                if(temp.size() == 3)
                {
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};