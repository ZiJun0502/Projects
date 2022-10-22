class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int T[128] = {};
        int count = t.size();
        for (int i = 0; i < count; i++) 
            T[t[i]]++;
        int mini = 1e5+5, last = 0, left = 0, i = 0;
        while(i <= s.size() && last < s.size()) {
            if(count) {
                if (i == s.size()) 
                    break;
                T[s[i]]--;
                if (T[s[i]] >= 0) 
                    count--;
                i++;
            } else {
                if (i - last < mini) {
                    mini = i -last;
                    left = last;
                }
                T[s[last]]++;
                if (T[s[last]] > 0) count++;
                last++;
            }
        }
        return mini == 1e5+5? "" : s.substr(left, mini);
    }
};