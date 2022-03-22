class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int len = height.size()-1;
        int r = len;
        int ans = 0;
        
        while(len--)
        {
            ans = max(ans, (r-l)*min(height[r],height[l]));
            if(height[l] > height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return ans;
    }
};