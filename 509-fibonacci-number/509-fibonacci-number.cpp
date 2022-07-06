class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return  n;
        }
        int a0 = 0;
        int a1 = 1;
        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            ans = a0 + a1;
            a0 = a1;
            a1 = ans;
        }
        return ans;
    }
};