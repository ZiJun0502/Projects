class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        short int count[201] = {};
        for(int i : nums){
            count[i+100]++;
        }
        vector<int> m[101];
        for(int i = 200 ; i >= 0 ; i--){
            if(count[i]){
                //cout << count[i]<<' '<<i-100 <<'\n';
                m[count[i]].push_back(i-100);
            }
        }
        vector<int> ans;
        int ind = 0;
        for(int i = 0 ; i <= 100 ; i++){
            if(m[i].size() > 0){
                for(int j : m[i]){
                    auto k = vector<int>(i, j);
                    ans.insert(ans.end(), k.begin(), k.end());
                }
            }
        }
        return ans;
    }
};