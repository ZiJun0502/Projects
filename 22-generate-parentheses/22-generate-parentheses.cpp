class Solution {
public:
    vector<string> ans;
    int n0;
    string s;
    void create(int l, int r)
    {
        if(l + r < 2 * n0)
        {
            if(l < n0){
                s += '(';
                create(l + 1, r);
                s.pop_back();
            }
            if(l > r){
                s+=')';
                create(l , r + 1);
                s.pop_back();
            }
        }
        else
            ans.push_back(s);
    }
    vector<string> generateParenthesis(int n) {
        n0 = n;
        create(0, 0);
        return ans;
    }
};