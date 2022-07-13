class Solution {
public:
    bool dp[301];
    bool wordBreak(string s, vector<string>& words) {
        dp[0] = 1;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(!dp[i]) continue;
            for(string word : words){
                int m = word.size();
                if(i + m <= n){
                    string temp = s.substr(i, m);
                    if(temp.compare(word) == 0){
                        dp[i] = 1;
                        dp[i + m] = 1;
                    }
                }
                
            }
        }
        //for(int i : dp) cout << i << ' ';
        return dp[n];
    }
};