class Solution {
public:
    int mySqrt(int x) {
        long mid;
        int l = 0, r = x, ans;
        while(r >= l){
            mid = r + l >> 1;
            
            long temp = mid * mid;
            //cout << temp << '\n';
            if(temp > x) r = mid-1;
            else if(temp < x){
                ans = mid;
                l = mid+1;
            }
            else return mid;
        }
        return ans;
    }
};