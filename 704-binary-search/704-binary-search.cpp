class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l=0;
        while(l<=r)
        {
            if(nums[(r+l)/2]==target)
                return (r+l)/2;
            else if(nums[(r+l)/2]>target)
                r = (r+l)/2-1;
            else
                l = (r+l)/2+1;
        }
        return -1;       
    }
};