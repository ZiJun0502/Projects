class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> m;
        for(string word: words){
            string temp;
            for(char c : word){
                temp += arr[c-'a'];
            }
            m.insert(temp);
        }
        return (int)m.size();
    }
};