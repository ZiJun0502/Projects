class Solution {
public:
    int cal(int min) {
        int ans = 0, temp = min / 15;
        if (temp > 0) {
            ans += temp;
            min -= 15 * temp;
        }
        temp = min / 5;
        if (temp > 0) {
            ans += temp;
            min -= 5 * temp;
        }
        ans += min;
        return ans;
    }
    int convertTime(string cur, string cor) {
        int n = 5, ans = 0, h1, h0, m1, m0;
        m1 = ((cor[3]-'0') * 10) + cor[4]-'0', m0 = ((cur[3]-'0') * 10) + cur[4]-'0';
        h1 = ((cor[0]-'0') * 10) + cor[1]-'0', h0 = ((cur[0]-'0') * 10) + cur[1]-'0';
        if (h0 > h1) {
            int ans = (24 - h0) + h1 + cal(m1 + (60 - m0));
            if (m0 > m1) return ans - 1;
            else return ans;
        }
        if (m0 > m1) return h1 - h0 - 1 + cal(m1 + (60 - m0));
        else return h1 - h0 + cal(m1 - m0);
    }
};