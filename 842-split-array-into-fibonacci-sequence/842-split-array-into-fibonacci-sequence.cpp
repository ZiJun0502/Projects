class Solution {
public:
    #define MAX 214748365
    int n;
    vector<int> ans;
    bool re(string s, int j=0, int last=0, int llast=0){
        int val = 0;
        if(j == n && ans.size() > 2){
            return 1;
        }
        if(INT_MAX - last < llast) return 0;
        for(int i = j ; i < n ; i++){
            if(val >= MAX) break;
            val = val * 10 + (s[i] - '0');
            if(last + llast == val || ans.size() < 2){
                ans.push_back(val);
                if(re(s, i+1, val, last)) return 1;
                ans.pop_back();
            }
            if(val == 0) break;
        }
        return 0;
    }
    vector<int> splitIntoFibonacci(string num) {
        n = num.size();
        re(num);
        return ans;
    }
};