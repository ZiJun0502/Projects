class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& types, int m) {
        sort(types.begin(), types.end(), cmp);
        int ans = 0;
        int count = 0;
        for(auto type : types)
        {
            int num = type[0];
            int val = type[1];
            //cout << type[0] <<' ' <<type[1]<<'\n';
            if(num < m - count)
            {
                ans += num * val;
                count += num;
            }
            else
            {
                ans += (m - count) * val;
                break;
            }
        }
        return ans;
    }
};