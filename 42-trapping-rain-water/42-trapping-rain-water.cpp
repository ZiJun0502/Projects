class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // leftMax[i] highest wall on the left side of i
        int leftMax[n];
        int rightMax[n];
        int maxi = 0;
        for(int i = 0 ; i < n ; i++)
        {
            leftMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        maxi = 0;
        for(int i = n-1 ; i > -1 ; i--)
        {
            rightMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        int ans = 0;
        for(int i = 1 ; i < n ; i++)
        {
            int h = min(leftMax[i], rightMax[i]);
            if(h > height[i])
            {
                ans += h - height[i];
            }
        }
        return ans;
    }
};