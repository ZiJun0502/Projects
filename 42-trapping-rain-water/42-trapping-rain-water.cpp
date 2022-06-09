class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        // leftMax[i] highest wall on the left side of i
        int lm = 0, rm = 0;
        int ans = 0;
        int l = 0, r = n - 1;
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