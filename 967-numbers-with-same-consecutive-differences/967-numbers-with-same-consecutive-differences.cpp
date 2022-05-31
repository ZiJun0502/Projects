class Solution {
public:
    int n;
    int k;
    vector<int> ans;
    void re(int len, int last, int num)
    {
        if(len == n) 
        {
            ans.push_back(num);
            return;
        }
        if(last + k < 10)
            re(len + 1, last + k, num * 10 + (last + k));
        if(last - k >= 0 && k != 0)
            re(len + 1, last - k, num * 10 + (last - k));
    }
    vector<int> numsSameConsecDiff(int n0, int k0) {
        n = n0;
        k = k0;
        for(int i = 1 ; i < 10 ; i++) re(1, i, i);
        return ans;
    }
};