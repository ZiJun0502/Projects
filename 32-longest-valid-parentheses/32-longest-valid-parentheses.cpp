class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int stack[n+1];
        stack[0] = -1;
        int size = 1;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] =='(')
            {
                stack[size++] = i;
            }
            else
            {
                if(size > 0)
                    size--;
                if(size == 0)
                {
                    stack[size++] = i;
                }
                else
                    ans = max(ans, i - stack[size - 1]);
            }
        }
        return ans;
    }
};