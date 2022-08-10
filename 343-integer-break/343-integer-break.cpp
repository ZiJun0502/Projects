class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n-1;
        int max1 = pow(2, n/2-1);
        int max2 = pow(3, n/3-1);
        if(n % 3 == 1) max2 *= 4;
        else if(n % 3 == 2) max2 *= 2 * 3;
        else max2 *= 3;
        if(n % 2 == 0) max1 *= 2;
        else max1 *= 3;
        //cout << par;
        return max(max1, max2);
    }
};