class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ans=0;
        int n = v.size()-1;
        int sum = 0;
        k --;
        for(int i = 0 ; i <= k ; i++)
            sum += v[i];
        ans = sum;
        for(int i = 0 ; i <= k ; i++)
        {
            sum += v[n-i];
            sum -= v[k-i];
            ans = max(sum, ans);
        }
        return ans;
    }
};