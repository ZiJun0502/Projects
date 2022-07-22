class Solution {
public:
    vector<vector<string>> ans;
    vector<string> vec;
    void hi(string s){
        int n = s.size();
        if(s.size() == 0){
            ans.push_back(vec);
            return ;
        }
        for(int i = 0 ; i < n ;i++){
            bool good = true;
            for(int j = 0 ; j <= i/2 ; j++){
                if(s[i-j] != s[j]) good = false;
            }
            if(good){
                vec.push_back(s.substr(0, i+1));
                hi(s.substr(i+1, n-i));
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        hi(s);
        return ans;
    }
};