class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> nums;
        string s;
        for(int i = 0 ; i < n ; i++)
        {
            s = words[i];
            bitset<26> m;
            for(char c : s)
            {
                m[c-'a'] = 1;
            }
            nums.push_back(m.to_ulong());
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
                if((nums[i] & nums[j]) == 0)
                {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};