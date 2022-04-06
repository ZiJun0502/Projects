class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOnes = 0, countFlips = 0;
        for (auto ch : s) 
        {
            if (ch == '1') 
                ++countOnes;
            else 
                ++countFlips;
            countFlips = min(countOnes, countFlips);
        }
        return countFlips;
    }
};