class Solution {
public:
    int n, m, tar = 0;
    int temp = 0, ans = 0;
    unordered_set<int> reco;
    vector<vector<int>> arr;
    void re(int now = 0){
        if(reco.size() == tar){
            int temp = n;
            //for(int i : reco)cout << i <<' ';
            //cout << '\n';
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(reco.find(j) != reco.end()) continue;
                    if(arr[i][j] == 1){
                        temp--;
                        break;
                    }
                }
            }
            ans = max(ans, temp);
            return;
        }
        for(int i = now ; i < m-(tar - reco.size())+1 ; i++){
            reco.insert(i);
            re(i+1);
            reco.erase(i);
        }
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        n = mat.size(), m = mat[0].size();
        tar = cols;
        arr = mat;
        re();
        return ans;
    }
};