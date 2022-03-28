class Solution {
public:
    vector<string> ans;
    int n0;
    void create(string s, int l, int r)
    {
        if(l + r < 2 * n0)
        {
            if(l < n0) create(s + '(', l + 1, r);
            if(l > r) create(s + ')', l , r + 1);
        }
        else
            ans.push_back(s);
    }
    vector<string> generateParenthesis(int n) {
        n0 = n;
        create("", 0, 0);
        return ans;
    }
};