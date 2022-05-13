class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return"11";
        string s = countAndSay(n-1);
        string ss;
        int l = s.size();
        int count;
        for(int i = 0 ; i < l ; i++)
        {
            count = 1;
            while(i != l - 1 && s[i] == s[i + 1])
            {
                count++;
                i++;
            }
            ss += to_string(count) + s[i];
        }
        return ss;
    }
};