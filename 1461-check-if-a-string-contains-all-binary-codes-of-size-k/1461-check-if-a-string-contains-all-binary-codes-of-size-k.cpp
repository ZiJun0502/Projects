class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> codes;
        int n = s.size();
        string sub;
        for(int i = 0 ; i < n - k + 1; i++)
        {
            sub = s.substr(i, k);
            codes.insert(sub);
        }
        int size = 1;
        //for(auto i : codes) cout << i <<'\n';
        for(int i = 0 ; i < k ; i++) size <<= 1;
        //cout <<size<<'\n';
        if(codes.size() == size) return true;
        return false;
    }
};