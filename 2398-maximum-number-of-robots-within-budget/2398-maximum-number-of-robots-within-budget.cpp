class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& costs, long long budget) {
        int ans = 0, l = 0, r = 0, n = charge.size();
        long long now = 0;
        priority_queue<int> p;
        while(r < n){
            p.push(charge[r]);
            now += costs[r++];
            while(budget < (r-l)*now + p.top() && r > l){
                if(charge[l] == p.top() && !p.empty()){
                    p.pop();
                }
                now -= costs[l++];
            }
            if(budget >= (r-l)*now + p.top()){
                //cout << l << ' ' << r <<'\n';
                ans = max(ans, (r-l));
            }
        }
        return ans;
    }
};