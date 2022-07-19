class Solution {
public:
    int numSplits(string s) {
        bitset<26> l;
        bitset<26> r;
        
        int n = s.size();
        int left[n];
        int right[n];
        memset(left, 0, 4*n);
        memset(right, 0, 4*n);
        for(int i = 0 ; i < n ; i++){
            if(l[s[i] - 'a'] == 0){
                if(i > 0)
                    left[i] = left[i-1]+1;
                else left[i]++;
                l[s[i] -'a'] = 1;
            }
            else left[i] = left[i-1];
        }
        for(int i = n-1 ; i > -1 ; i--){
            if(r[s[i] - 'a'] == 0){
                if(i < n-1)
                    right[i] = right[i+1]+1;
                else right[i]++;
                r[s[i] -'a'] = 1;
            }
            else right[i] = right[i+1];
        }
        int ans = 0;
        for(int i = 0 ; i < n-1 ;i++){
            if(left[i] == right[i+1]){
                ans++;
            }
        }
        return ans;
    }
};