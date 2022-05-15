class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor == -1){
            return 2147483647;
        }
        return dividend / divisor;
    }
};