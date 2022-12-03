class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        map<int,vector<char>> freqToC;
        for(auto& i : m){
            freqToC[i.second].push_back(i.first);
        }
        string ans;
        for(auto j = freqToC.rbegin() ; j != freqToC.rend() ; j++){
            for(char c : j->second){
                for(int i = 0 ; i < j->first ; i++){
                    ans.push_back(c);
                }
            }
        }
        return ans;
    }
};