class Solution {
public:
    long long ans = 0;
    int kk;
    void merge_sort(vector<int>& v){
        int n = v.size();
        if(n > 1){
            vector<int> left = vector<int>(v.begin(), v.begin() + n/2);
            vector<int> right = vector<int>(v.begin()+n/2, v.end());
            merge_sort(left);
            merge_sort(right);
            merge(v, left, right);
        }
        else return; 
    }
    void merge(vector<int>& v, vector<int> l, vector<int> r){
        int now = 0, ll = 0, rr = 0;
        int good = 0;
        while(ll < l.size() && rr < r.size()){
            if(r[rr]+kk >= l[ll]){
                ans += r.size() - rr;
                ll++;
            }else{
                rr++;
            }
            
        }
        ll = rr = 0;
        while(ll < l.size() && rr < r.size()){
            if(r[rr] > l[ll]){
                v[now++] = l[ll++];
            }
            else{
                v[now++] = r[rr++];
            }
        }
        while(ll < l.size()){
            v[now++] = l[ll++];
        }
        while(rr < r.size()){
            v[now++] = r[rr++];
        }
    }
    long long numberOfPairs(vector<int> nums1, vector<int> nums2, int diff) {
        vector<int> temp;
        int n = nums1.size();
        temp = vector<int>(n);
        kk = diff;
        for(int i = 0 ; i < n ; i++){
            temp[i] = nums1[i] - nums2[i];
        }
        merge_sort(temp);
        return ans;
    }
};