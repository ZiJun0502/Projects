class Solution {
public:
    int longestBeautifulSubstring(string word) {
    int n = word.size();
    int ans = 0, temp = 0;
    char dic[] = "aeiou";
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (now == 0 && word[i] == 'a') {
            now++;
            temp++;
        }
        else if (now > 0) {
            if (now < 5 && word[i] == dic[now]) {
                now++;
                temp++;
            }
            else if (word[i] == dic[now - 1]) {
                temp++;
            }
            else {
                temp = 0;
                now = 0;
                if (word[i] == 'a'){
                    temp++, now++;
                }
            }
        }
        if (now == 5) ans = max(ans, temp);
    }
    return ans;
}
};