class Solution {
public:
    int trap(vector<int>& height) {
        int right = 0, left = 0, lm = 0, rm = 0; // max;
        int l = 0, r = height.size()-1, ans = 0;
        while(r > l){
            right = height[r], left = height[l];
            if(right > left){
                if(left < lm){
                    ans += lm - left;
                }
                else{
                    lm = left;
                }
                l++;
            }
            else{
                if(right < rm){
                    ans += rm - right;
                }
                else rm = right;
                r--;
            }
        }
        return ans;
    }
};