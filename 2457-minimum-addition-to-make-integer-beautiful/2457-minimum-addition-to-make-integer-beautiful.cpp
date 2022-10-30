class Solution {
public:
    long long p(long long a, long long b){
        long long ans = 1, cnt = 1;
        while(b){
            int t = b%2;
            if(t) ans *= cnt;
            cnt*=cnt;
            b/=2;
        }
        return ans;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        vector<int> arr;
        long long c = n, cnt = 0, dig = 0;
        while(c){
            int temp = c % 10;
            cnt += temp;
            dig++;
            c /= 10;
            arr.push_back(temp);
        }
        reverse(arr.begin(), arr.end());
        if(cnt > target){
            long long k = 0, temp = 0, ans = 0, subn = 0;
            for(int i : arr){
                temp += i;
                if(temp > target){
                    temp -= i;
                    break;
                }
                k++;
            }
            for(int i = k ; i < dig ; i++){
                subn = subn*10 + arr[i];
            }
            ans += pow((long long)10, dig - k) - subn;
            long long j = 1;
            while(j <= k && temp + 1 > target){
                subn = pow((long long)10,(long long)(dig-k+j-1))*(arr[k-j]+1);
                
                //cout << subn << '\n';
                ans += pow((long long)10, (long long)(dig - k + j)) - subn;
                //cout << ans << '\n';
                temp = temp - (arr[k-j]);
                j++;
            }
            return ans;
        }
        return 0;
    }
};