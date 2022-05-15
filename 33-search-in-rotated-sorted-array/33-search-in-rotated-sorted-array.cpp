class Solution {
    int bsearch(int s , int e , vector<int>&nums,int target){
        while(s <= e){
            int mid = (s+e)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] > target)e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            return (target == nums[0] ? 0 : -1);
        }
        
        int s = 0,e = n-1,ans;
        while(s+1 < e){
            int mid = (s+e)/2;
            if(nums[mid] > nums[s]){
                s = mid;
            }else{
                e = mid;
            }
        }
        if(nums[s] < nums[e]){
            return bsearch(0,n-1,nums,target);
        }
        else if(target <= nums[n-1]){
            return bsearch(e,n-1,nums,target);
        }else{
            return bsearch(0,s,nums,target);
        }
    }
    
};