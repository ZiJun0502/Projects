class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOnes = 0, countFlips = 0;
        for (int i = 0 ; i < s.size() ; i++) 
        {
            if (s[i] == '1') 
                ++countOnes;
            else 
                ++countFlips;
            countFlips = min(countOnes, countFlips);
        }
        return countFlips;
    }
};