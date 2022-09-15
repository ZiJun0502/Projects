class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int m[100001] = {};
        sort(begin(changed), end(changed), greater<int>());
        vector<int> ans;
        int count = changed.size();
        //if(count % 2) return {};
        while(count > 0 && changed[count-1] == 0){
            count--;
            m[0]++;
        }
        if(m[0] % 2 == 0){
            ans = vector<int>(m[0]/2, 0);
            //changed.resize(count);
        }else return {};
        //cout << count << '\n';
        int size = count;
        for(int j = 0 ; j < size ; j++){
            //cout << i << ' ';
            m[changed[j]]++;
            if(changed[j] < 50001 && m[changed[j]*2]>0){
                ans.push_back(changed[j]);
                m[changed[j]]--, m[changed[j]*2]--;
                count -= 2;
            }
        }
        //cout << count ;
        if(!count)
        return ans;
        else return {};
    }
};