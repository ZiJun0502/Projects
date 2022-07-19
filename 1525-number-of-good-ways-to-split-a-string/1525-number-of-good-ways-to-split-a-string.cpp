class Solution {
public:
    int numSplits(string s) {
        //initialize
        bitset<26> l;
        bitset<26> r;
        
        int n = s.size();
        int left[n];
        int right[n];
        memset(left, 0, 4*n);
        memset(right, 0, 4*n);
        left[0] = right[n-1] = 1;
        l[s[0]-'a'] = 1, r[s[n-1] - 'a'] = 1;
        //loop from left to right.
        for(int i = 1 ; i < n ; i++){
            left[i] = left[i-1];
            if(l[s[i] - 'a'] == 0){
                left[i]++;
                l[s[i] -'a'] = 1;
            }
        }
        //loop from right to left.
        for(int i = n-2 ; i > -1 ; i--){
            right[i] = right[i+1];
            if(r[s[i] - 'a'] == 0){
                right[i]+=1;
                r[s[i] -'a'] = 1;
            }
        }
        //check good points.
        int ans = 0;
        for(int i = 0 ; i < n-1 ;i++){
            if(left[i] == right[i+1]){
                ans++;
            }
        }
        return ans;
    }
};