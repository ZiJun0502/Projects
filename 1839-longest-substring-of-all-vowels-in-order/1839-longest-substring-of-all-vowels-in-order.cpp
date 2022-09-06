class Solution {
public:
    int longestBeautifulSubstring(string word) {
    int n = word.size();
    int ans = 0, j = 0;
    for(int i = 0 ; i < n-4 ; ++i) {
        if (word[i] == 'a') {
            int count = 0;
            for(j = i+1 ; j < n && word[j] >= word[j-1]; j++){
                if(word[j] != word[j-1]) count++;
            }
            if(count == 4) ans = max(ans, j-i);
            i = j-1;
        }
    }
    return ans;
}
};