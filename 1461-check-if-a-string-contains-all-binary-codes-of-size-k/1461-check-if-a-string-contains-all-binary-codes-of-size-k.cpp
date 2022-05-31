class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<int> codes;
        string sub;
        int len = s.size() - k + 1;
        for(int i = 0 ; i < len; i++)
        {
            sub = s.substr(i, k);
            int j = 0;
            for(int l = k-1 ; l >= 0 ; l--)
            {
                j = (j << 1) + (sub[l] - '0');
            }
            codes.insert(j);
        }
        int size;
        //for(auto i : codes) cout << i <<'\n';
        size = pow(2, k);
        //cout <<size<<'\n';
        if(codes.size() == size) return true;
        return false;
    }
};