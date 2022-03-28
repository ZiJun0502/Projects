class Solution {
public:
    vector<string> ans;
    int n0;
    void create(int count, string s, int l, int r)
    {
        if(count < 2 * n0)
        {
            if(l < n0) create(count + 1, s + '(', l + 1, r);
            if(l > r) create(count + 1, s + ')', l , r + 1);
        }
        else
            ans.push_back(s);
    }
    vector<string> generateParenthesis(int n) {
        n0 = n;
        create(0, "", 0, 0);
        return ans;
    }
};