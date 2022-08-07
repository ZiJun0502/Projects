class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& d) {
        int n = d.size();
        int gc = d[0];
        for(int i = 1 ; i < n ; i++){
            gc = __gcd(gc, d[i]);
        }
        cout << gc <<' ';
        sort(nums.begin(),nums.end());
        int i = 0;
        int count = 0;
        while(i < nums.size()){
            if(gc % nums[i] == 0){
                return count;
            }
            if(nums[i] > gc) return -1;
            count++, i++;
        }return -1;
    }
};