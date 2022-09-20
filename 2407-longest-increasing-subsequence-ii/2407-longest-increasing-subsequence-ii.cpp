class Solution {
public:
    int seg[300003];
    int ans[100001];
    int query(int l, int r, int l0, int r0, int ind = 1){
        if(l > r0 || r < l0) return 0;
        if(l0 >= l && r0 <= r) return seg[ind];
        int mid = l0 + r0 >> 1;
        int left = query(l, r, l0, mid, ind*2);
        int right = query(l, r, mid+1, r0, ind*2+1);
        return max(left, right);
    }
    int set_val(int l0, int r0, int i, int val, int ind = 1){
        if(l0 == r0) return seg[ind] = val;
        int mid = l0 + r0 >> 1, maxi;
        if(mid >= i){
            maxi = set_val(l0, mid, i, val, ind*2);
        }else maxi = set_val(mid+1, r0, i, val, ind*2+1);
        seg[ind] = max(seg[ind], maxi);
        return seg[ind];
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0 ; i < n ; i++){
            int temp = query(max(nums[i]-k, mini), nums[i]-1, mini, maxi);
            if(temp >= ans[nums[i]]){
                ans[nums[i]] = temp+1;
                set_val(mini, maxi, nums[i], temp+1);
            }
            //for(int i = mini ; i <= maxi ; i++) cout << ans[i]<<' ';cout << '\n';
        }
        return seg[1];
    }
};