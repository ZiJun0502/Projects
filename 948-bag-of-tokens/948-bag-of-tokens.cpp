class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0, r = tokens.size()-1, n = tokens.size();
        if(r < 0) return 0;
        sort(tokens.begin() , tokens.end());
        int ans = 0;
        while(r > l || l < n && power >= tokens[l]){
            if(power >= tokens[l]){
                ans++;
                power -= tokens[l];
                l++;
            }
            else if (ans > 0){
                power += tokens[r];
                ans--;
                r--;
            }
            else break;
        }
        return ans;
    }
};