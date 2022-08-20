class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size(), ans = 0;
        bool done = 1;
        while(done != 0){
            done = 0;
            for(int i = 1 ; i < n ; i++){
                if(s[i-1] =='0' && s[i] == '1'){
                    done = 1;
                    swap(s[i-1], s[i]);
                    i++;
                    //cout << i <<'\n';
                }//cout << i <<'\n';
            }//cout << s <<'\n';
            ans += done;
        }
        
        return ans;
    }
};