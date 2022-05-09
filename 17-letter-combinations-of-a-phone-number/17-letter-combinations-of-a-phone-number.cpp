class Solution {
public:
    map<char, string> m;
    string s;
    int len;
    vector<string> ans;
    void solver(string temp, int count = 0)
    {
        if(count < len)
        {
            for(auto i : m[temp[count]])
            {
                s.push_back(i);
                solver(temp, count + 1);
                s.pop_back();
            }
        }
        else if(count == len) ans.push_back(s);
    }
    vector<string> letterCombinations(string digits) {
        len = digits.size();
        if (digits.size() == 0) return ans;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        solver(digits);
        return ans;
    }
};