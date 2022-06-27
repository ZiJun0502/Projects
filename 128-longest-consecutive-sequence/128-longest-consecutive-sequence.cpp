class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int i : nums) m.insert(i);
        int ans = 0;
        unordered_set<int>::iterator it;
        for(it = m.begin(); it != m.end();)
        {
            int l = 1;
            int num = *it;
            int iter = num;
            while(m.find(iter-1) != m.end())
            {
                m.erase(iter-1);
                iter--;
                l++;
            }
            iter = num;
            while(m.find(iter+1) != m.end())
            {
                m.erase(iter+1);
                iter++;
                l++;
            }
            it = m.erase(it);
            ans = max(ans, l);
        }
        return ans;
    }
};