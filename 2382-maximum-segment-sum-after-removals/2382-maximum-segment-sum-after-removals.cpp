class Solution {
public:
    vector<long long> group, parent;
    int find(int i){
        if(parent[i] == i) return i;
        else return parent[i] = find(parent[i]);
    }
    void merge(int i, int j){
        int head1 = find(j);
        int head2 = find(i);
        if(head1 == head2) return;
        group[head1] += group[head2];
        group[head2] = group[head1];
        parent[head2] = head1;
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& Q) {
        int n = nums.size();

        vector<long long> ans(n);
        ans[n - 1] = 0;
        group.resize(n), parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = n - 1; i > 0; i--) {
            int ind = Q[i];
            group[ind] = nums[ind];
            if (ind > 0 && group[ind-1] != 0) merge(ind, ind - 1);
            if (ind < n - 1 && group[ind + 1] != 0) merge(ind, ind + 1);
            ans[i - 1] = max(ans[i], group[find(ind)]);
        }
        //for (int i : group) cout << i << ' ';

        return ans;
}
};