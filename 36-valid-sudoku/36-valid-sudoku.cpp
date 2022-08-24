class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis[10] = {};
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ;j ++){
                if(board[i][j] == '.') continue;
                if(vis[board[i][j]-'0'] ) return false;
                vis[board[i][j]-'0'] = 1;
            }
            memset(vis, 0, sizeof(vis));
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i] == '.') continue;
                if(vis[board[j][i]-'0']) return false;
                vis[board[j][i]-'0'] = 1;
            }
            memset(vis, 0, sizeof(vis));
        }
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    for(int l = 0 ; l < 3 ; l++){
                        if(board[i*3+k][j*3+l]=='.') continue;
                        if(vis[board[i*3+k][j*3+l]-'0']) return false;
                        vis[board[i*3+k][j*3+l]-'0'] = 1;
                    }
                }
                memset(vis, 0, sizeof(vis));
            }
        }
        return true;
    }
};