class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count,ans = 0;
        for(auto i : nums)
        {
            count = 0;
            while(i!=0)
            {
                i/=10; count++;
            }
            if(count % 2 == 0) ans++;
        }
        return ans;
    }
};