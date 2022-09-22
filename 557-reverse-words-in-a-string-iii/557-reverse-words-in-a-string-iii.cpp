class Solution {
public:
    string reverseWords(string s) {
        int now = -1, last = -1;
        int n = s.size();
        for(;;){
            now = s.find(' ', now+1);
            if(now == -1) break;
            reverse(s.begin()+last+1, s.begin()+now);
            //cout << s<<'\n';
            last = now;
        }
        reverse(s.begin()+last+1, s.begin()+n);
        return s;
    }
};