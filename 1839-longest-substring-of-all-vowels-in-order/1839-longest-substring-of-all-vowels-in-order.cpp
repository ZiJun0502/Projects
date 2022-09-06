class Solution {
public:
    int longestBeautifulSubstring(string word) {
    int ans = 0, temp = 0;
    char dic[] = "aeiou";
    int now = 0;
    for(char c : word) {
        if (now == 0 && c == 'a') {
            now = 1;
            temp = 1;
        }
        else if (now > 0) {
            if (now < 5 && c == dic[now]) {
                now++;
                temp++;
            }
            else if (c == dic[now - 1]) {
                temp++;
            }
            else {
                temp = 0;
                now = 0;
                if (c == 'a'){
                    temp = 1, now = 1;
                }
            }
        }
        if (now == 5) ans = max(ans, temp);
    }
    return ans;
}
};