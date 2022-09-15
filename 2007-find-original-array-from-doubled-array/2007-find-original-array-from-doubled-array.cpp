class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int m[100001] = {};
        sort(begin(changed), end(changed), greater<int>());
        vector<int> ans;
        int count = changed.size();
        for(int i : changed){
            //cout << i << ' ';
            m[i]++;
            if(i < 50001 && i != 0 && m[i*2]>0 || i == 0 && m[i] > 1){
                ans.push_back(i);
                m[i]--, m[i*2]--;
                count -= 2;
            }
        }
        //cout << count ;
        if(!count)
        return ans;
        else return {};
    }
};