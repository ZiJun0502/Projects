class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1,high = n,ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};
