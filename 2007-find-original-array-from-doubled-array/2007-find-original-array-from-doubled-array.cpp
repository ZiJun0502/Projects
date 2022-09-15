class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> m;
        sort(begin(changed), end(changed), greater<int>());
        vector<int> ans;
        
        for(int i : changed){
            //cout << i << ' ';
            m[i]++;
            if(i != 0 && m.find(i*2) != m.end() || i == 0 && m[i] > 1){
                ans.push_back(i);
                m[i]--, m[i*2]--;
                if(m[i] == 0) m.erase(i);
                if(m[i*2] == 0) m.erase(i*2);
            }
        }
        if(m.empty())
        return ans;
        else return {};
    }
};