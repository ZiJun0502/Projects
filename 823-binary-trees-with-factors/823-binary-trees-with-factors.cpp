class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int,long long> m;
        for(int i : arr){
            long long count = 1;
            for(auto j : m){
                int key = j.first;
                if(i % key == 0 && m.find(i / key) != m.end()){
                    count += m[key] * m[i / key];
                }
            }
            m[i] = count;
        }
        long ans = 0;
        for(auto i : m){
            ans = (ans + i.second) % mod;
        }
        return ans;
    }
};