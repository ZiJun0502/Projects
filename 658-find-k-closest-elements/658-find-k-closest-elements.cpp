class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(x > arr[n-1]) return vector<int>(arr.end()-k, arr.end());
        if(x < arr[0]) return vector<int>(arr.begin(), arr.begin()+k);
        int i = lower_bound(arr.begin() ,arr.end(), x) - arr.begin();
        if(i > 0 && arr[i] - x >= x - arr[i-1]) i--;
        k--;
        int l = i-1, r = i+1;
        //cout << i << ' ';
        while(r < n && l >= 0 && k--){
            if((arr[r] - x) < (x - arr[l])){
                r++;
            }
            else l--;
        }
        //cout << r << ' ' << l << ' ' << k << '\n';
        if(k <= 0) return vector<int>(arr.begin() + l + 1, arr.begin() + r);
        if(r == n) return vector<int>(arr.begin() + l + 1 - k, arr.end());
        if(l ==-1) return vector<int>(arr.begin(), arr.begin() + r + k);
        return {};
    }
};