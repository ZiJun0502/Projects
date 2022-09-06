class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        sort(begin(as), end(as));
        long long l = 0, m = mass, n = as.size();
        while(l < n){
            if(m < as[l]) return 0;
            m += as[l++];
        }
        return true;
    }
};