class Solution {
public:
    #define MAX 922337203685477580
    int n;
    bool re(string& s, int j=0, long long last=0, long long llast=0, int size=0){
        long long val = 0;
        if(j == n && size > 2){
            return 1;
        }
        for(int i = j ; i < n ; i++){
            if(val > MAX) break;
            if(val == MAX && (s[i]-'0' > 7)) break;
            val = val * 10 + (s[i] - '0');
            if(last + llast == val || size < 2){
                if(re(s, i+1, val, last, size+1)) return 1;
            }
            if(val == 0) break;
        }
        return 0;
    }
    bool isAdditiveNumber(string num) {
        n = num.size();
        return re(num);
    }
};