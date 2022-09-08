class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = 0, r = 0, current = 0;
        int n = heights.size();
        pair<int,int> stack[n];
        int size = 0;
        int left[n], right[n];
        memset(left,0,sizeof(left)), memset(right, 0, sizeof(right));
        stack[size++] = {0, heights[0]};
        right[n-1] = n;
        for(int i = 1 ; i < n ; i++){
            while(size > 0 && heights[i] < stack[size-1].second){
                right[stack[size-1].first] = i;
                size--;
            }
            stack[size++] = {i, heights[i]};
        }
        while(size--){
            right[stack[size].first] = n;
        }
        left[0] = -1;
        stack[0] = {n-1, heights[n-1]};
        size = 1;
        for(int i = n-2 ; i >= 0 ; i--){
            while(size > 0 && heights[i] < stack[size-1].second){
                left[stack[size-1].first] = i;
                size--;
                //cout << i << ' ';
            }
            stack[size++] = {i, heights[i]};
        }
        while(size--){
            left[stack[size].first] = -1;
        }
        int temp = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            temp = heights[i] * (right[i] - left[i] - 1);
            //cout << temp << ' ' << left[i] << ' ' <<right[i] <<'\n';
            ans = max(temp, ans);
        }
        return ans;
    }
};