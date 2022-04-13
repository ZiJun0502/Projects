class Solution {
public:
    vector<int>::iterator vec;
    int x, y;
    bool dp(int start, int end)
    {
        
        if(end - start < 1)
        {
            if(end == start)
            {
                x += vec[start];
            }
            if(x >= y) {
                if(end == start)
                x -= vec[start];
                return true;
            }
            if(end == start)
            x -= vec[start];
            return false;
        }
        bool a,b;
        x += vec[start];
        y += vec[end];
        a = dp(start + 1, end - 1);
        y -= vec[end];
        
        y += vec[start+ 1];
        b = dp(start + 2, end);
        y -= vec[start + 1];
        x -= vec[start];
        if(a && b) return true;
        
        x += vec[end];
        y += vec[end - 1];
        a = dp(start, end - 2);
        y -= vec[end - 1];
        
        y += vec[start];
        b = dp(start + 1, end - 1);
        y -= vec[start];
        x -= vec[end];
        
        if(a && b) return true;
        return false;
    }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return true;
        }
        vec = nums.begin();
        return dp(0, nums.size() - 1);
    }
};