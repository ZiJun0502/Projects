class Solution {
public:
    #define MAX 214748365
    int n;
    vector<int> temp;
    vector<int> ans;
    void re(string s, int j, int last, int llast){
        int val = 0;
        //cout << j << '\n';
        
        if(j == n && ans.size() > 2){
            temp = ans;
        }
        if(INT_MAX - last < llast) return;
        for(int i = j ; i < n ; i++){
            if(val >= MAX) break;
            val = val * 10 + (s[i] - '0');
            if(last + llast == val || ans.size() < 2){
                ans.push_back(val);
                re(s, i+1, val, last);
                ans.pop_back();
            }
            if(val == 0) break;
        }
    }
    vector<int> splitIntoFibonacci(string num) {
        n = num.size();
        re(num, 0, 0, 0);
        return temp;
    }
};