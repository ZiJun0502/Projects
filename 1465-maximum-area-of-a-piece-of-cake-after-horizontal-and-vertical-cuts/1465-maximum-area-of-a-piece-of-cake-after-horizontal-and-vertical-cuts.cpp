class Solution {
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(), hs.end());
        sort(vs.begin(), vs.end());
        int n = hs.size();
        long long maxh = hs[0];
        for(int i = 1 ; i < n ; i++)
        {
            maxh = max(maxh, (long long)(hs[i] - hs[i-1]));
        } maxh = max(maxh, (long long)(h - hs[n-1]));
        n = vs.size();
        long long maxv = vs[0];
        for(int i = 1 ; i < n ; i++)
        {
            maxv = max(maxv, (long long)(vs[i] - vs[i-1]));
        } maxv = max(maxv,(long long)(w - vs[n-1]));
        return (maxh * maxv) % (long long)(1e9+7);
    }
};