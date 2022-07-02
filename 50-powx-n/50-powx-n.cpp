class Solution {
public:
    double myPow(double x, int n) {
        unsigned int nn = n;
        double ans = 1;
        if(n < 0) nn = -nn;
        while(nn)
        {
            if(nn % 2 == 0)
            {
                x *= x;
                nn /= 2;
            }
            else
            {
                ans *= x;
                nn -= 1;
            }
        } 
        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};