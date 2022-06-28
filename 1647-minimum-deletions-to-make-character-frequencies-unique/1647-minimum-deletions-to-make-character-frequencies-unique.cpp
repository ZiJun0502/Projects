class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char c : s) 
            freq[c-'a']++;
        int ans = 0;
        sort(freq.begin(), freq.end());
        for(int i = 24 ; i > -1 ; i--)
        {
            if(!freq[i]) break;
            if(freq[i+1] <= freq[i])
            {
                ans+=freq[i] - freq[i+1] + 1;
                freq[i] = freq[i+1] - 1;
                if(freq[i+1] == 0)
                {
                    ans--,freq[i]++;
                }
            }
            
        }
        return ans;
    }
};