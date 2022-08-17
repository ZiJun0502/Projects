class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> m;
        string temp;
        for(string word: words){
            for(char c : word){
                temp += arr[c-'a'];
            }
            m.insert(temp);
            temp = "";
        }
        return m.size();
    }
};