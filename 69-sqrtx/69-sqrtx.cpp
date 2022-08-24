class Solution {
public:
    int mySqrt(int x) {
        long mid;
        int l = 0, r = x;
        while(r >= l){
            mid = r + l >> 1;
            
            long temp = mid * mid;
            //cout << temp << '\n';
            if((mid+1)*(mid+1) > x && temp < x || temp == x) return mid;
            else if(temp > x){
                r = mid-1;
            }
            else if(temp < x) l = mid+1;
        }
        return l;
    }
};