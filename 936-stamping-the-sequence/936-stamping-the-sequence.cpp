class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int count = 0, n = target.size(), m = stamp.size();
        auto check = [&](int start, int len){
            for(int i = 0 ; i < len ; i++){
                if(target[i + start] != stamp[i] && target[i + start] != '?') return 0;
            }
            return 1;
        };
        auto Stamp = [&](int start, int len){
            for(int i = 0 ; i < len ; i++){
                if(target[i + start] != '?'){
                    target[i + start] = '?';
                    count ++;
                }
                
            }
        };
        bool temp;
        int round = 0;
        while(count != n){
            temp = 0;
            for(int i = 0 ; i < n ; i++){
                if(check(i, m)){
                    Stamp(i, m);
                    ans.push_back(i);
                    temp = 1;
                    round++;
                }
            }
            if(!temp || round > 10 * n) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};