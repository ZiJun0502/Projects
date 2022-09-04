class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        int m = meetings.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> p;
        long long j = 0;
        long long time = meetings[0][0];
        set<int> empty;
        for (int i = 0; i < n; i++) empty.insert(i);
        vector<int> ans(n);
        for (auto& meet : meetings) {
            // no room
            back:
            while(p.size() > 0 && time >= p.top().first || empty.empty()) {
                auto temp = p.top();
                p.pop();
                if(empty.empty()){
                    time = max(temp.first, time);
                }
                empty.insert(temp.second);
            }
            if(time < meet[0]){
                time = meet[0];
                goto back;
            }
            int room = *empty.begin();
            empty.erase(empty.begin());
            //{endtime, room used}
            p.push({ time + meet[1] - meet[0], room });
            ans[room]++;
        }
        //for (int i : ans)cout << i << ' '; cout << '\n';
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};