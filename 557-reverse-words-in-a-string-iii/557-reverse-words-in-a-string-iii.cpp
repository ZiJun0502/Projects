class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string sss;
        int now = 0;
        while(ss >> sss){
            //cout << sss << '\n';
            reverse(sss.begin(),end(sss));
            for(int i = 0 ; i < sss.size() ; i++){
                s[now++] = sss[i];
            }
            s[now++] = ' ';
        }
        return s;
    }
};