class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int arr[26][n+1];
        memset(arr, 0, sizeof(arr));
        for(int i = 0 ; i < n ; i++){
            arr[s[i]-'a'][i+1]++;
        }
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < n ;j ++){
                arr[i][j+1] += arr[i][j];
            }
        }
        vector<bool> ans;
        for(vector<int>& q : queries){
            int l = q[0], r = q[1], k = q[2];
            int len = 0;
            for(int i = 0 ; i < 26 ; i++){
                len += (arr[i][r+1] - arr[i][l]) % 2;
            }
            // ebyvmjqbmb
            
            //cout << len << '\n';
            //cout << count <<' ' << len << '\n';
            ans.push_back(k >= len / 2);
        }
        return ans;
        
    }
};