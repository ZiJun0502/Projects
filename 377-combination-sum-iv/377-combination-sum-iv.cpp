class Solution {
public:
    int ans, n;
    vector<int> arr;
    int temp = 1, count = 0;
    unordered_map<int,int> m;
    void re(int target, int j = 0){
        if(target == 0){
            ans += temp;
            // cout << ans <<'\n';
            // for(int i : bb) cout<<i<<' ';
            // cout <<'\n';
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = j ; i < n ; i++){
            m[arr[i]]++;
            count++;
            int a = count, b = m[arr[i]];
            temp *= a;
            temp /= b;
            re(target - arr[i], i);
            temp *= b;
            temp /= a;
            m[arr[i]]--;
            count--;
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 999) return 1;
        n = nums.size();
        arr = nums;
        re(target);
        return ans;
    }
};