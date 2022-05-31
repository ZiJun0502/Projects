class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> codes;
        int n = s.size();
        int j;
        string sub;
        for(int i = 0 ; i < n - k + 1; i++)
        {
            sub = s.substr(i, k);
            j = 0;
            for(int l = k-1 ; l >= 0 ; l--)
            {
                j = (j << 1) + (sub[l] - '0');
            }
            codes.insert(j);
        }
        int size = 1;
        //for(auto i : codes) cout << i <<'\n';
        for(int i = 0 ; i < k ; i++) size <<= 1;
        //cout <<size<<'\n';
        if(codes.size() == size) return true;
        return false;
    }
};