class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>& b)
    {
        if(a[0] > b[0]) return true;
        else if(a[0] < b[0]) return false;
        else return a[1]<b[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        //for(auto i : people) cout << i[0] <<' ' << i[1] <<'\n';
        for(int i = 0 ; i < n ; i++)
        {
            int j = people[i][1];
            ans.insert(ans.begin() + j, people[i]);
        }
        return ans;
    }
};