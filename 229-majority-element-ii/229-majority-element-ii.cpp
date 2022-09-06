class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int a = -1, b = -1, c = 0, c1 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == a){
                c++;
            }
            else if(nums[i] == b){
                    c1++;
            }
            else if(c==0){
                a = nums[i];
                c++;
            }
            else if(c1==0){
                b = nums[i];
                c1++;
            }
            else{
                c--;
                c1--;
            }
        }
        c1 = c = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == a) c++;
            else if(nums[i] == b) c1++;
        }
        vector<int> ans;
        if(c > n/3) ans.push_back(a);
        if(c1 > n/3) ans.push_back(b);
            
        return ans;
    }
};