class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0, count = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] =='('){
                count++;
            }else{
                if(count){
                    if(i+1 < n && s[i+1] == ')'){
                        i++;
                        count--;
                    }else{
                        ans++;
                        count--;
                    }
                }
                else{
                    if(i+1 < n && s[i+1] ==')'){
                        ans++;
                        i++;
                    }
                    else{
                        ans += 2;
                    }
                }
            }
        }
        return count*2 + ans;
    }
};