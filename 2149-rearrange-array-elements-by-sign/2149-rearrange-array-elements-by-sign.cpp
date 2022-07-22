class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        int* pos = new int[n/2];
        int* neg = new int[n/2];
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= 0){
                pos[a++] = nums[i];
            }
            else{
                neg[b++] = nums[i];
            }
        }
        a=0,b=0;
        int count = 0;
        n/=2;
        for(int i = 0 ; i < n ;i++){
            nums[count++] = pos[a++];
            nums[count++] = neg[b++];
        }
        return nums;
    }
};