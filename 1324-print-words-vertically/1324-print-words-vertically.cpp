class Solution {
public:
    vector<string> printVertically(string s) {
        char arr[200][200];
        short int len[200];
        memset(arr, ' ', 40000*sizeof(char));
        int n = s.size();
        int j = 0, size = 0, maxi = 0;
        for(int i = 0 ; i < n; i++){
            if(s[i] == ' '){
                j++;
                size = 0;
                continue;
            }
            len[size] = j;
            arr[size++][j] = s[i];
            maxi = max(maxi, size);
        }
        vector<string> ans;
        for(int i = 0 ; i < maxi ; i++){
            string s;
            for(int k = 0 ; k <= len[i] ; k++){
                s.push_back(arr[i][k]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};