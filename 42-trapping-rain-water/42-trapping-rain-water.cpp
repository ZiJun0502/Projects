class Solution {
public:
    int trap(vector<int>& h) {
        int r = h.size() - 1, l = 0, lm = 0, rm = 0;
        int ans = 0;
        int right, left;
        while(r > l)
        {
            right = h[r], left = h[l];
            if(right > left)
            {
                if(left < lm) 
                    ans += lm - left;
                else
                    lm = left;
                l++;
            }
            else
            {
                if(right < rm)
                    ans += rm - right;
                else
                    rm = right;
                r--;
            }
        }
        return ans;
    }
};