class Solution {
public:
    vector<int> diffWaysToCompute(string s){
        int n = s.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> lres = diffWaysToCompute(s.substr(0, i));
                vector<int> rres = diffWaysToCompute(s.substr(i+1, n-i));
                for(int l : lres){
                    for(int r : rres){
                        if(s[i] == '+') ans.push_back(l+r);
                        if(s[i] == '-') ans.push_back(l-r);
                        if(s[i] == '*') ans.push_back(l*r);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(s));
        return ans;
    }
};