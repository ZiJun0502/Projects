class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> codes;
        string sub;
        int len = s.size() - k + 1;
        for(int i = 0 ; i < len; i ++)
        {
            int val = 0;
            for(int j = i ; j < i + k  ; j++)
            {
                val = (val << 1) + s[j] - '0';
            }
            codes.insert(val);
        }
        int size;
        //for(auto i : codes) cout << i <<'\n';
        size = pow(2, k);
        //cout <<size<<'\n';
        if(codes.size() == size) return true;
        return false;
    }
};