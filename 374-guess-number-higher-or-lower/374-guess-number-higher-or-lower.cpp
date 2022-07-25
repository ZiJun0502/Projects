/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        long long mid;
        while(r > l){
            mid = (r + l)/2;
            if(guess(mid) == 1){
                l = mid+1;
            }
            else if(guess(mid) == 0){
                return mid;
            }
            else r = mid-1;
            
        }
        mid = (r + l)/2;
        return mid;
    }
};