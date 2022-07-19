class Solution {
public:
    int numSplits(string s) {
        bitset<26> l;
        bitset<26> r;
        
        int n = s.size();
        short int left[n];
        short int right[n];
        memset(left, 0, 2*n);
        memset(right, 0, 2*n);
        left[0] = right[n-1] = 1;
        l[s[0]-'a'] = 1, r[s[n-1] - 'a'] = 1;
        for(int i = 1 ; i < n ; i++){
            left[i] = left[i-1];
            if(l[s[i] - 'a'] == 0){
                left[i]++;
                l[s[i] -'a'] = 1;
            }
        }
        for(int i = n-2 ; i > -1 ; i--){
            right[i] = right[i+1];
            if(r[s[i] - 'a'] == 0){
                right[i]++;
                r[s[i] -'a'] = 1;
            }
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