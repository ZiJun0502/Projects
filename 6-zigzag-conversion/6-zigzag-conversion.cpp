#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
class Solution {
public:
    string convert(string s, int numRows) {
        IOS;
        // distance between the first char and next char
        int dist = 2 * (numRows - 1);
        // when count == 1, we print s[first + dist +- count], the chars in front of and right behind the next pos
        int count;
        // length
        int len = s.length();
        if(numRows == 1 || len == 1) return s;
        string ss = s ; int k = 0; 
        // how many char in first row;
        int n = len / dist + 1;
        int maxd = max(len, n*dist+1);
        for(count = 0 ; count < numRows ; count++)
        {
            for(int i = 0 ; i < maxd ; i += dist)
            {
                if (count == 0 && i < len){
                    ss[k++] = s[i];
                }
                else
                {
                    if(i - count >= 0 && i - count < len) ss[k++] = s[i-count];
                    if(i + count < len && !(count == dist - count)) ss[k++] = s[i+count];
                }
            }
        }
        return ss;
    }
};