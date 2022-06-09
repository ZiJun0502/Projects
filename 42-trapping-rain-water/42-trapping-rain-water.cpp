class Solution {
public:
    int trap(vector<int>& h) {
        int r = h.size() - 1, l = 0, lm = 0, rm = 0;
        int ans = 0;
        while(r > l)
        {
            if(h[r] > h[l])
            {
                if(h[l] < lm) 
                    ans += lm - h[l];
                else
                    lm = h[l];
                l++;
            }
            else
            {
                if(h[r] < rm)
                    ans += rm - h[r];
                else
                    rm = h[r];
                r--;
            }
        }
        return ans;
    }
};