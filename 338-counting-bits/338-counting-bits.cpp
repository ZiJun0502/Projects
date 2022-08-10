class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0 ; i <= n ; i++){
            int num = i;
            while(num){
                if(num % 2 == 1){
                    ans[i]++;
                }
                num/=2;
            }
        }
        return ans;
    }
};