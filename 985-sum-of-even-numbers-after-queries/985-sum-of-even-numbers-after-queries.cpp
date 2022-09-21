class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int now = 0;
        for(int &i : nums) if(i % 2 == 0) now += i;
        int n = nums.size();
        vector<int> ans(n);
        int i = 0;
        for(auto& q : queries){
            int ind = q[1], val = q[0];
            int temp = nums[ind], tempp = temp + val;
            if(temp % 2 == 0) {
                if(val % 2 == 0) now += val;
                else now -= temp;
            }
            else{
                if(val % 2 != 0) now += temp + val;
            }
            nums[ind] += val;
            ans[i++] = now;
        }
        return ans;
    }
};