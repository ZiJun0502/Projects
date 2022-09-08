class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int stack[n];
        memset(stack, 0 , sizeof(stack));
        int size = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            while(size > 0 && heights[i] < heights[stack[size-1]]){
                int height = heights[stack[--size]];
                int width = size > 0 ? i - stack[size-1] : i + 1;
                ans = max(ans, height * (width-1));
            }
            stack[size++] = i;
        }
        
        return ans;
    }
};