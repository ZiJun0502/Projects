class Solution {
public:
    #define MAX 214748365
    int n;
    vector<int> temp;
    vector<int> ans;
    bool re(string s, int j, int last, int llast){
        int val = 0;
        if(j == n && ans.size() > 2){
            return true;
        }
        if(INT_MAX - last < llast) return 0;
        for(int i = j ; i < n ; i++){
            if(val >= MAX) break;
            val = val * 10 + (s[i] - '0');
            if(last + llast == val || ans.size() < 2){
                ans.push_back(val);
                if(re(s, i+1, val, last)) return true;
                ans.pop_back();
            }
            if(val == 0) break;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        n = num.size();
        re(num, 0, 0, 0);
        return ans;
    }
};