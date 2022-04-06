class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0, countFlips = 0;
        for (int i = 0 ; i < s.size() ; i++) 
        {
            if (s[i] == '1') 
                ++count1;
            else 
                ++countFlips;
            countFlips = min(count1, countFlips);
        }
        return countFlips;
    }
};