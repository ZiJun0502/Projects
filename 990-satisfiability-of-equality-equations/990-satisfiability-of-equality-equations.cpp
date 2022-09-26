class Solution {
public:
    char temp[28];
    char find(char c){
        if(temp[c - 'a'] == c) return c;
        return temp[c-'a'] = find(temp[c -'a']);
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        int now = 0;
        for(int i = 0 ; i < n ; i++){
            if(equations[i][1] == '='){
                swap(equations[i], equations[now++]);
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            temp[i] = 'a' + i;
        }
        for(string s : equations){
            char a = find(s[0]);
            char b = find(s[3]);
            if(s[1] == '!'){
                if(a == b) return false;
            }else{
                temp[a - 'a'] = b;
            }
        }
        return true;
    }
};