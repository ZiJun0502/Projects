class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0, mini = 0;
        int right = n - k;
        int left = 0;
        for(int i = 0 ; i < right ; i++){
            mini += v[i];
            sum += v[i];
        }
        int ans = mini;
        for(int i = right ; i < n ; i++)
        {
            sum += v[i];
            mini += v[i] - v[left++];
            ans = min(mini, ans);
        }
        return sum - ans;
    }
};