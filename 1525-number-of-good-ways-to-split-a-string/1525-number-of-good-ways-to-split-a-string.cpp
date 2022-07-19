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
        left[0] = right[n-1] = 1;
        l[s[0]-'a'] = 1, r[s[n-1] - 'a'] = 1;
        for(int i = 1 ; i < n ; i++){
            if(l[s[i] - 'a'] == 0){
                left[i] = left[i-1]+1;
                l[s[i] -'a'] = 1;
            }
            else left[i] = left[i-1];
        }
        for(int i = n-2 ; i > -1 ; i--){
            if(r[s[i] - 'a'] == 0){
                right[i] = right[i+1]+1;
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