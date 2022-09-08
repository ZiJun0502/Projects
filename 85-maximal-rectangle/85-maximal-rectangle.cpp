class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int stack[100000] = {};
        //memset(stack, 0 , sizeof(stack));
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
    
    int maximalRectangle(vector<vector<char>>& ma) {
        int n = ma.size(), m = ma[0].size();
        vector<int> pre(m);
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(ma[i][j] == '1') pre[j]++;
                else pre[j] = 0;
            }
            ans = max(largestRectangleArea(pre), ans);
        }
        return ans;
    }
};